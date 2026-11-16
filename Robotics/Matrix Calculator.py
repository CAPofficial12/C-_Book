import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

CSV         = "Measured File.csv"
GYRO_IN_DEG = False     # True if the CSV gyro is in deg/s
TAU_STAR    = 30.0      # seconds over which the filter should be able to track bias
WN_WINDOW   = (0.05, 2.0)   # white-noise (slope -0.5) window in seconds. CHECK on the plot.
MIN_CLUSTERS = 9        # caps tau at T/9 so every point has a usable confidence

df = pd.read_csv(CSV)
t  = df["Time_s"].to_numpy(float)
dt = np.median(np.diff(t))
gyro = df[["Gyro_X", "Gyro_Y", "Gyro_Z"]].to_numpy(float)
acc  = df[["Accel_X", "Accel_Y", "Accel_Z"]].to_numpy(float)
if GYRO_IN_DEG:
    gyro = np.deg2rad(gyro)

def allan(x, dt):
    x = x[np.isfinite(x)]
    x = x - x.mean()
    n = len(x)
    max_m = n // MIN_CLUSTERS
    ms = np.unique(np.logspace(0, np.log10(max_m), 60).astype(int))
    c = np.concatenate(([0.0], np.cumsum(x)))
    tau, adev = [], []
    for m in ms:
        avg  = (c[m:] - c[:-m]) / m
        diff = avg[m:] - avg[:-m]
        tau.append(m * dt)
        adev.append(np.sqrt(0.5 * np.mean(diff**2)))
    return np.array(tau), np.array(adev)

def fixed_slope_coeff(tau, adev, lo, hi, slope):
    """Fit only the coefficient with the slope fixed to the theoretical value."""
    mk = (tau >= lo) & (tau <= hi) & (adev > 0)
    if mk.sum() < 3:
        raise ValueError("Not enough points in window")
    return 10 ** np.mean(np.log10(adev[mk]) - slope * np.log10(tau[mk]))

def adev_at(tau, adev, t0):
    return 10 ** np.interp(np.log10(t0), np.log10(tau), np.log10(adev))

names = ["X", "Y", "Z"]
N, Qg, Qb = [], [], []
plt.figure()
for i, nm in enumerate(names):
    tau, adev = allan(gyro[:, i], dt)
    n_i = fixed_slope_coeff(tau, adev, *WN_WINDOW, -0.5)        # rad/sqrt(s)
    a_s = adev_at(tau, adev, TAU_STAR)
    # remove the white-noise contribution at tau*, then convert to an RRW density
    var_rrw = max(a_s**2 - n_i**2 / TAU_STAR, 1e-12)
    qb_i = 3.0 * var_rrw / TAU_STAR                              # (rad/s)^2 / s
    N.append(n_i); Qg.append(n_i**2); Qb.append(qb_i)
    plt.loglog(tau, adev, label=f"Gyro {nm}")
    plt.loglog(tau, n_i / np.sqrt(tau), "k:", lw=0.8)
    plt.plot(TAU_STAR, a_s, "ko")

plt.axvspan(*WN_WINDOW, alpha=0.1)
plt.xlabel("tau (s)"); plt.ylabel("Allan deviation (rad/s)")
plt.grid(True, which="both"); plt.legend(); plt.show()

# R: isotropic accelerometer noise in units of g, from the normalised accel
g_ref = np.mean(np.linalg.norm(acc, axis=1))
a_g   = acc / g_ref
r0    = np.mean(np.var(a_g, axis=0, ddof=1))

print("\n--- paste into the C++ ---")
print("const d QG[3] = {%.6e, %.6e, %.6e};" % tuple(Qg))
print("const d QB[3] = {%.6e, %.6e, %.6e};" % tuple(Qb))
print("const d R0    = %.6e;" % r0)
print("\nN (rad/sqrt(s)):", N)
print("g_ref (CSV accel units):", g_ref)