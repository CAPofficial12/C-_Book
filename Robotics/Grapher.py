import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("EKF output.csv")
plt.plot(df["Step"], df["Roll"])
plt.grid(True)
plt.show()