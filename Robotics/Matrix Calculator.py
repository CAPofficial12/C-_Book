import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def Allan_Variance(data):

    data = np.asarray(data, dtype=float)
    data = data[np.isfinite(data)]
    data -= np.mean(data)

    dt = np.median(np.diff(df["Time_s"]))
    
    N = len(data)
    min_pairs = 100
    max_m = N//min_pairs
    m_values = np.unique(np.logspace(0, np.log10(max_m), 60).astype(int))

    tau, variance = [], []
    cumulative = np.concatenate(([0.0], np.cumsum(data)))
    for m in m_values:

        average = (cumulative[m:] - cumulative[:-m]) / m
        differences = average[m:] - average[:-m]
        allan_variance = 0.5*np.mean(differences**2)

        tau.append(m*dt)
        variance.append(allan_variance)

    return tau, np.sqrt(variance)

def Allan_Parameters(tau, adev, tau_min, tau_max, expected_slope):
    tau = np.asarray(tau)
    adev = np.asarray(adev)

    mask = (
        (tau >= tau_min) &
        (tau <= tau_max) &
        (adev > 0)
    )

    if mask.sum() < 3:
        raise ValueError("Not enough points in fitting range")

    x = np.log10(tau[mask])
    y = np.log10(adev[mask])

    slope, intercept = np.polyfit(x, y, 1)
    coefficient = 10**intercept

    print(f"Fitted slope: {slope:.3f}")

    if abs(slope - expected_slope) > 0.15:
        print("WARNING: Fitted slope is not close to the expected slope.")

    return coefficient

df = pd.read_csv("Measured File.csv")

Accel = df[["Accel_X", "Accel_Y", "Accel_Z"]].to_numpy(dtype=float)
Gyro = df[["Gyro_X", "Gyro_Y", "Gyro_Z"]].to_numpy(dtype=float)

for i, axis in enumerate(["Gyro_X", "Gyro_Y", "Gyro_Z"]):

    data = Gyro[:, i]

    median = np.median(data)
    mad = np.median(np.abs(data - median))

    threshold = 6 * 1.4826 * mad

    outliers = np.abs(data - median) > threshold

    print(
        axis,
        "Outliers:", np.sum(outliers),
        "Total samples:", len(data)
    )

Means = [df["Accel_X"].mean(), df["Accel_Y"].mean(), df["Accel_Z"].mean()]
Variance = [df["Accel_X"].var(), df["Accel_Y"].var(), df["Accel_Z"].var()]

mag = np.linalg.norm(Accel, axis=1)
valid = mag > 1e-12
Accel_normalized = Accel[valid] / mag[valid, None]

R = np.cov(
    Accel_normalized,
    rowvar=False,
    ddof=1
)

print("\nAccelerometer covariance R:")
print(R)

#Allan Deviation
tauX, varianceX = Allan_Variance(Gyro[:, 0])
tauY, varianceY = Allan_Variance(Gyro[:, 1])
tauZ, varianceZ = Allan_Variance(Gyro[:, 2])

N_X = Allan_Parameters(tauX, varianceX, 0.5, 1, -0.5)
N_Y = Allan_Parameters(tauY, varianceY, 0.5, 1, -0.5)
N_Z = Allan_Parameters(tauZ, varianceZ, 0.5, 10, -0.5)

K_X = np.sqrt(3) * Allan_Parameters(tauX, varianceX, 130, 900, 0.5)
K_Y = np.sqrt(3) * Allan_Parameters(tauY, varianceY, 70, 200, 0.5)
K_Z = np.sqrt(3) * Allan_Parameters(tauZ, varianceZ, 100, 200, 0.5)

print("\nContinuous process noise covariance Qc:")
Qc = [N_X**2, N_Y**2, N_Z**2, K_X**2, K_Y**2, K_Z**2]
print(np.array(Qc))

