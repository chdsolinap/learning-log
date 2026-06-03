import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
from scipy.integrate import solve_ivp
from scipy.signal import TransferFunction, impulse

# Time vector
t_vals = np.linspace(0, 10, 400)

# Define symbolic variables
s, t = sp.symbols('s t', real=True)

# --- PROBLEMS 1–3: Inverse Laplace Transforms using impulse response and symbolic computation ---

systems = [
    ([6, 20], [1, 8, 20, 32]),  # F1(s)
    ([1, 6, 34], [1, 7, 25, 50]),  # F2(s)
    ([1, 18, 115, 250], [1, 12, 74, 232, 376, 240])  # F3(s)
]

titles = ["Problem 1: F₁(s)", "Problem 2: F₂(s)", "Problem 3: F₃(s)"]

plt.figure(figsize=(15, 15))

for i, (num, den) in enumerate(systems):
    sys = TransferFunction(num, den)
    t_num, y = impulse(sys, T=t_vals)

    # Symbolic Inverse Laplace - CORRECTED
    num_expr = sum(coef * s**i for i, coef in enumerate(reversed(num)))
    den_expr = sum(coef * s**i for i, coef in enumerate(reversed(den)))
    F_s = num_expr / den_expr
    f_t = sp.inverse_laplace_transform(F_s, s, t)

    print(f"{titles[i]} Inverse Laplace Transform:")
    sp.pprint(f_t)
    print("\n" + "-"*50 + "\n")

    plt.subplot(3, 2, i+1)
    plt.plot(t_num, y)
    plt.title(f"{titles[i]} - Inverse Laplace via Impulse")
    plt.xlabel("Time t")
    plt.ylabel("f(t)")
    plt.grid(True)

# --- PROBLEM 4: y'' + 4y' + 3y = cos(2t), y(0)=1, y'(0)=0 ---

def system4(t, Y):
    y1, y2 = Y
    return [y2, np.cos(2*t) - 4*y2 - 3*y1]

sol4 = solve_ivp(system4, (0, 10), [1, 0], t_eval=t_vals)

plt.subplot(3, 2, 4)
plt.plot(sol4.t, sol4.y[0], color='green')
plt.title("Problem 4: y'' + 4y' + 3y = cos(2t)")
plt.xlabel("Time t")
plt.ylabel("y(t)")
plt.grid(True)

# --- PROBLEM 5: y'' + 2y' + 5y = e^(-t), y(0)=0, y'(0)=1 ---

def system5(t, Y):
    y1, y2 = Y
    return [y2, np.exp(-t) - 2*y2 - 5*y1]

sol5 = solve_ivp(system5, (0, 10), [0, 1], t_eval=t_vals)

plt.subplot(3, 2, 6)
plt.plot(sol5.t, sol5.y[0], color='purple')
plt.title("Problem 5: y'' + 2y' + 5y = e^(-t)")
plt.xlabel("Time t")
plt.ylabel("y(t)")
plt.grid(True)

plt.tight_layout()
plt.show()
