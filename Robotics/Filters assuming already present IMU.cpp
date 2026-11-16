#include <bits/stdc++.h>
#include <chrono>
#include <Eigen/Dense>
#include <cmath>

using d = float;
using namespace std;
using ll = long long int;

d interval = 0.1;

Eigen::Matrix<d, 3, 1> accel = {0, 1, 0};
Eigen::Matrix<d, 3, 1> gyro = {0.0f, 0.0f, 0.0f};

Eigen::Matrix<d, 7, 7> I = Eigen::Matrix<d, 7, 7>::Identity();
Eigen::Matrix<d, 7, 7> P;
Eigen::Quaternionf q(1.0, 0.0, 0.0, 0.0);
Eigen::Matrix<d, 7, 1> X = {q.w(), q.x(), q.y(), q.z(), 0, 0, 0};
                                     
d square(d x);

vector<vector<float>> Open(string s){
    ifstream file(s);

    vector<vector<float>> grid;
    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<float> row;

        while (getline(ss, cell, ',')) {
            if (!cell.empty()) {
                row.push_back(stof(cell));
            } else {
                row.push_back(0.0f);
            }
        }
        grid.push_back(row);
    }
    file.close();
    return grid;
}


int main() {
    ofstream file("EKF Untuned output.csv");
    file << "Step,Roll,Pitch,Yaw\n";                                                                   

    P.setZero();
    P.diagonal() << 0.01f, 0.01f, 0.01f, 0.01f,
        0.001f, 0.001f, 0.001f;

    vector<vector<float>> data = Open("Measured File.csv");
    for(ll i = 1; i < data.size(); i++){
        accel = {data[i][4], data[i][5], data[i][6]};
        gyro = {data[i][10], data[i][11], data[i][12]};
        interval = data[i][0] - data[i-1][0];

        Eigen::Quaternionf Omega(0, gyro(0) - X(4), gyro(1) - X(5), gyro(2) - X(6));
        
        auto q0 = q.w(), q1 = q.x(), q2 = q.y(), q3 = q.z();
        Eigen::Matrix<d, 7, 7> F;
        F << 1.0, -Omega.x()/2*interval, -Omega.y()/2*interval, -Omega.z()/2*interval, q1/2*interval, q2/2*interval, q3/2*interval, 
        Omega.x()/2*interval, 1.0, Omega.z()/2*interval, -Omega.y()/2*interval, -q0/2*interval, q3/2*interval, -q2/2*interval, 
        Omega.y()/2*interval, -Omega.z()/2*interval, 1.0, Omega.x()/2*interval, -q3/2*interval, -q0/2*interval, q1/2*interval, 
        Omega.z()/2*interval, Omega.y()/2*interval, -Omega.x()/2*interval, 1.0, q2/2*interval, -q1/2*interval, -q0/2*interval, 
        0, 0, 0, 0, 1.0, 0, 0, 
        0, 0, 0, 0, 0, 1.0, 0, 
        0, 0, 0, 0, 0, 0, 1.0;

        auto q_dot = (q * Omega);
        q_dot.coeffs() *= interval / 2;
        q.coeffs() += q_dot.coeffs();
        q.normalize();

        q0 = q.w(), q1 = q.x(), q2 = q.y(), q3 = q.z();
        X.block(0, 0, 4, 1) << q0, q1, q2, q3;
        

        
        Eigen::Matrix<d, 7, 6> G;
        G << q1, q2, q3, 0, 0, 0,
            -q0, q3, -q2, 0, 0, 0,
            -q3, -q0, q1, 0, 0, 0,
            q2, -q1, -q0, 0, 0, 0,
            0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1;

        G.block(0, 0, 4, 3) *= 0.5f;

        d qgx = 2.81128651e-07, qgy = 4.73870860e-08, qgz = 3.93258274e-07;
        d qbx = 3.80912632e-09, qby = 1.88103746e-09, qbz = 1.02978778e-08;
        Eigen::Matrix<d, 6, 6> Qc;
        Qc << qgx, 0, 0, 0, 0, 0,
                0, qgy, 0, 0, 0, 0,
                0, 0, qgz, 0, 0, 0,
                0, 0, 0, qbx, 0, 0,
                0, 0, 0, 0, qby, 0,
                0, 0, 0, 0, 0, qbz;  

        Eigen::Matrix<d, 7, 7> Qd = G * Qc * G.transpose() * interval;
        Eigen::Matrix<d, 7, 7> Pp = F * P * F.transpose() + Qd;

        d a_mag = sqrt(square(accel(0)) + square(accel(1)) + square(accel(2)));
        auto z = 1/a_mag * accel;

        Eigen::Matrix<d, 3, 1> h;
        h << 2*(q1*q3 - q0*q2),
        2*(q0*q1 + q2*q3),
        square(q0) - square(q1) - square(q2) + square(q3);

        auto residual = z - h;

        Eigen::Matrix<d, 3, 7> H;
        H << -2*q2, 2*q3, -2*q0, 2*q1, 0, 0, 0,
        2*q1, 2*q0, 2*q3, 2*q2, 0, 0, 0,
        2*q0, -2*q1, -2*q2, 2*q3, 0, 0, 0;

        Eigen::Matrix<d, 3, 3> R;
        R << 1.31806750e-05,  5.42912242e-07, -1.51333311e-06,
            5.42912242e-07,  1.35999836e-05, -3.73449415e-06,
            -1.51333311e-06, -3.73449415e-06,  1.16758472e-06;
        R = 0.5f * (R + R.transpose());

        Eigen::Matrix<d, 3, 3> S;
        S = H * Pp * H.transpose() + R;

        Eigen::Matrix<d, 7, 3> K;
        K = S.ldlt().solve(H * Pp).transpose();

        X += K*residual;

        q = Eigen::Quaternionf(X(0), X(1), X(2), X(3));
        q.normalize();
        q0 = q.w(), q1 = q.x(), q2 = q.y(), q3 = q.z();
        X.block(0, 0, 4, 1) << q0, q1, q2, q3;

        P = (I-K*H) * Pp * (I-K*H).transpose()+ K*R*K.transpose();
        P = 0.5f * (P + P.transpose());

        d Roll = atan2(2*(q0*q1 + q2*q3), 1-2*(q1*q1 + q2*q2));

        d pitch_arg = 2*(q0*q2 - q3*q1);
        pitch_arg = std::clamp(pitch_arg, -1.0f, 1.0f);
        d Pitch = asin(pitch_arg);

        d Yaw = atan2(2*(q0*q3 + q1*q2), 1-2*(q3*q3 + q2*q2));

        file << i << ", " << Roll*180/3.1415 << ", " << Pitch*180/3.1415 << ", " << Yaw*180/3.1415 << "\n";
    }
    file.close();
    return 0;
}

d square(d x){
    return x*x;
}