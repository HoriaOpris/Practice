import pandas as pd

import matplotlib.pyplot as plt

# Read simulation data

df = pd.read_csv("simulation.csv")

# -----------------------------

# Speed Plot

# -----------------------------

plt.figure(figsize=(10, 5))

plt.plot(df["time"], df["actual_speed"],

         label="Actual Speed",

         linewidth=2)

plt.plot(df["time"], df["target_speed"],

         "--",

         label="Target Speed",

         linewidth=2)

plt.xlabel("Time (s)")

plt.ylabel("Speed (m/s)")

plt.title("Cruise Control Speed Response")

plt.grid(True)

plt.legend()

plt.tight_layout()

plt.show()

# -----------------------------

# Throttle Plot

# -----------------------------

plt.figure(figsize=(10, 4))

plt.plot(df["time"],

         df["throttle"],

         linewidth=2)

plt.xlabel("Time (s)")

plt.ylabel("Throttle (%)")

plt.title("Throttle Command")

plt.grid(True)

plt.tight_layout()

plt.show()