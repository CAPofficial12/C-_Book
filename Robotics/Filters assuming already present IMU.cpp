#include <bits/stdc++.h>
#include <Eigen/Dense>

using d  = double;
using ll = long long;
using namespace std;
using V3 = Eigen::Matrix<d,3,1>;
using M3 = Eigen::Matrix<d,3,3>;
using V7 = Eigen::Matrix<d,7,1>;
using M7 = Eigen::Matrix<d,7,7>;

// ---------------- configuration ----------------
const int  T_COL = 0, AX_COL = 4, GX_COL = 10;
const d    GYRO_TO_RAD = 1.0;       // M_PI/180.0 if the CSV gyro is deg/s
const int  N_INIT = 150;            // robot must be STILL for the first ~2 s
const d    DT_MAX = 0.25;           // skip steps after dropped samples

// Paste the Python output here
const d QG[3] = {3.113216e-07, 4.812177e-08, 4.058982e-07};
const d QB[3] = {1.000000e-13, 2.225717e-10, 9.690053e-10};
const d R0    = 2.359467e-05;

// Tuning scalars (adjust using NIS)
const d QB_MULT   = 1.0;    // multiplies bias process noise
const d SCALE_ERR = 0.02;   // gyro scale/cross-axis error fraction (0.01-0.03)
const d R_LIN     = 1e-3;   // lateral-acceleration term, ~(a_rms/g)^2/3
const d K_DEV     = 5.0;    // weight on | |a|-g |/g
const d K_W       = 0.01;   // weight on |omega|^2 (centripetal / gyroscopic)
const d NIS_LIMIT = 7.81;   // chi-square, 3 dof, 95%

vector<vector<d>> Open(const string& s) {
    ifstream file(s);
    vector<vector<d>> grid;
    string line;
    getline(file, line);                       // header
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<d> row;
        while (getline(ss, cell, ',')) {
            try { row.push_back(cell.empty() ? 0.0 : stod(cell)); }
            catch (...) { row.push_back(0.0); }
        }
        grid.push_back(row);
    }
    return grid;
}

int main() {
    vector<vector<d>> data = Open("Measured File.csv");
    if (data.size() <= (size_t)N_INIT + 1) { cerr << "Not enough data\n"; return 1; }

    // ---------- initialisation from the stationary start ----------
    V3 aMean = V3::Zero(), gMean = V3::Zero();
    for (int i = 0; i < N_INIT; i++) {
        aMean += V3(data[i][AX_COL], data[i][AX_COL+1], data[i][AX_COL+2]);
        gMean += V3(data[i][GX_COL], data[i][GX_COL+1], data[i][GX_COL+2]);
    }
    aMean /= N_INIT;
    gMean = gMean / N_INIT * GYRO_TO_RAD;

    const d G_REF = aMean.norm();              
    V3 an = aMean / G_REF;
    d roll0  = atan2(an.y(), an.z());
    d pitch0 = asin(std::clamp(-an.x(), -1.0, 1.0));
    d cr = cos(roll0/2), sr = sin(roll0/2), cp = cos(pitch0/2), sp = sin(pitch0/2);
    Eigen::Quaterniond q(cr*cp, sr*cp, cr*sp, -sr*sp);   // yaw = 0
    q.normalize();

    V7 X;
    X << q.w(), q.x(), q.y(), q.z(), gMean;

    M7 P = M7::Zero();
    P.diagonal() << 1e-4, 1e-4, 1e-4, 1e-4, 4e-6, 4e-6, 4e-6;
    const M7 I = M7::Identity();

    cout << "Initial roll/pitch (deg): " << roll0*180/M_PI << ", " << pitch0*180/M_PI << "\n";
    cout << "Initial gyro bias: " << gMean.transpose() << "\n";
    cout << "Gravity reference (CSV units): " << G_REF << "\n";

    ofstream file("EKF output.csv");
    file << "Step,Time,Roll,Pitch,Yaw,BiasX,BiasY,BiasZ,NIS\n";

    d nisSum = 0; ll nisCount = 0;

    for (size_t i = N_INIT; i < data.size(); i++) {
        if (data[i].size() < 13) continue;
        d dt = data[i][T_COL] - data[i-1][T_COL];
        if (dt <= 0 || dt > DT_MAX) continue;

        V3 acc(data[i][AX_COL], data[i][AX_COL+1], data[i][AX_COL+2]);
        V3 gyr = V3(data[i][GX_COL], data[i][GX_COL+1], data[i][GX_COL+2]) * GYRO_TO_RAD;
        V3 w = gyr - X.segment<3>(4);          // bias-corrected rate

        d q0 = q.w(), q1 = q.x(), q2 = q.y(), q3 = q.z();
        d h = dt / 2.0;

        // ---------- Jacobians (evaluated at the pre-propagation state) ----------
        M7 F;
        F << 1,      -w.x()*h, -w.y()*h, -w.z()*h,  q1*h,  q2*h,  q3*h,
             w.x()*h, 1,        w.z()*h, -w.y()*h, -q0*h,  q3*h, -q2*h,
             w.y()*h, -w.z()*h, 1,        w.x()*h, -q3*h, -q0*h,  q1*h,
             w.z()*h,  w.y()*h, -w.x()*h, 1,        q2*h, -q1*h, -q0*h,
             0,0,0,0, 1,0,0,
             0,0,0,0, 0,1,0,
             0,0,0,0, 0,0,1;

        // ---------- propagate ----------
        Eigen::Quaterniond Omega(0, w.x(), w.y(), w.z());
        Eigen::Quaterniond qd = q * Omega;
        q.coeffs() += qd.coeffs() * h;
        q.normalize();
        q0 = q.w(); q1 = q.x(); q2 = q.y(); q3 = q.z();
        X.head<4>() << q0, q1, q2, q3;

        Eigen::Matrix<d,7,6> G;
        G << q1, q2, q3, 0,0,0,
            -q0, q3,-q2, 0,0,0,
            -q3,-q0, q1, 0,0,0,
             q2,-q1,-q0, 0,0,0,
             0,0,0, 1,0,0,
             0,0,0, 0,1,0,
             0,0,0, 0,0,1;
        G.block<4,3>(0,0) *= 0.5;

        Eigen::Matrix<d,6,6> Qc = Eigen::Matrix<d,6,6>::Zero();
        for (int k = 0; k < 3; k++) { Qc(k,k) = QG[k]; Qc(k+3,k+3) = QB[k] * QB_MULT; }

        M7 Qd = G * Qc * G.transpose() * dt;

        // rate-dependent gyro error (scale factor / cross-axis) grows with |w|
        Eigen::Matrix<d,7,3> Gg = G.block<7,3>(0,0);
        M3 Qrate = M3::Zero();
        for (int k = 0; k < 3; k++) Qrate(k,k) = SCALE_ERR*SCALE_ERR * w(k)*w(k);
        Qd += Gg * Qrate * Gg.transpose() * dt * dt;

        M7 Pp = F * P * F.transpose() + Qd;

        // ---------- measurement ----------
        d a_mag = acc.norm();
        if (a_mag < 1e-9) continue;
        V3 z = acc / a_mag;

        V3 hm;
        hm << 2*(q1*q3 - q0*q2),
              2*(q0*q1 + q2*q3),
              q0*q0 - q1*q1 - q2*q2 + q3*q3;
        V3 residual = z - hm;

        Eigen::Matrix<d,3,7> H;
        H << -2*q2,  2*q3, -2*q0,  2*q1, 0,0,0,
              2*q1,  2*q0,  2*q3,  2*q2, 0,0,0,
              2*q0, -2*q1, -2*q2,  2*q3, 0,0,0;

        // adaptive isotropic R: static noise + lateral + |a|-g + rotation terms
        d dev = fabs(a_mag - G_REF) / G_REF;
        d s2  = R0 + R_LIN + K_DEV*dev*dev + K_W*w.squaredNorm();
        M3 R  = s2 * M3::Identity();

        M3 S = H * Pp * H.transpose() + R;
        d nis = residual.dot(S.ldlt().solve(residual));
        if (nis > NIS_LIMIT) {                 // soften instead of rejecting
            R *= nis / NIS_LIMIT;
            S = H * Pp * H.transpose() + R;
        }

        Eigen::Matrix<d,7,3> K = S.ldlt().solve(H * Pp).transpose();
        X += K * residual;

        q = Eigen::Quaterniond(X(0), X(1), X(2), X(3));
        q.normalize();
        q0 = q.w(); q1 = q.x(); q2 = q.y(); q3 = q.z();
        X.head<4>() << q0, q1, q2, q3;

        M7 IKH = I - K * H;
        P = IKH * Pp * IKH.transpose() + K * R * K.transpose();
        P = 0.5 * (P + P.transpose());

        nisSum += nis; nisCount++;

        d Roll  = atan2(2*(q0*q1 + q2*q3), 1 - 2*(q1*q1 + q2*q2));
        d Pitch = asin(std::clamp(2*(q0*q2 - q3*q1), -1.0, 1.0));
        d Yaw   = atan2(2*(q0*q3 + q1*q2), 1 - 2*(q2*q2 + q3*q3));

        file << i << "," << data[i][T_COL] << ","
             << Roll*180/M_PI << "," << Pitch*180/M_PI << "," << Yaw*180/M_PI << ","
             << X(4) << "," << X(5) << "," << X(6) << "," << nis << "\n";
    }

    cout << "Average NIS: " << (nisCount ? nisSum / nisCount : 0.0)
         << "  (target ~3)\n";
    return 0;
}