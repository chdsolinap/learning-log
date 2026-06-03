import sympy as sp
import matplotlib.pyplot as plt

# Define symbols for time t and complex frequency s
t, s = sp.symbols('t s', real=True)

# Define Heaviside step function u(t) and Dirac Delta functions
u = sp.Heaviside(t)
delta = sp.DiracDelta(t)

# Define the given time-domain functions f(t)
functions = [
    3 * delta + (4 * sp.exp(-2*t) + 8 * sp.exp(-5*t) * sp.cos(3*t) - 2 * sp.exp(-4*t) * sp.sin(5*t) - 6 * sp.exp(-3*t)) * u,
    8 * delta + (7 * sp.exp(-3*t) - 8 * sp.exp(-4*t) + 4 * sp.cosh(2*t) + 6 * sp.sinh(5*t)) * u,
    (7 * t**3 * sp.exp(-3*t) + 5 * sp.exp(-3*t) * sp.cosh(4*t) - 5 * sp.sin(4*t) * sp.cos(2*t) + 2 * t**3 * sp.sinh(3*t)) * u,
    (sp.sin(t) * u + 2 * sp.sin(t - sp.pi) * sp.Heaviside(t - sp.pi) - sp.exp(-2 * (t - 2*sp.pi)) * sp.Heaviside(t - 2*sp.pi)),
    (sp.cosh(3*t) * sp.sin(2*t)) / (t * sp.exp(4*t))
]

# Solve each function consecutively
for i, f in enumerate(functions, 1):
    
    # Show the function
    print(f"\nFunction {i}: f(t) =", f)

    # Compute Laplace Transforms
    F_s = sp.laplace_transform(f, t, s, noconds=True)
    F_s_pretty = sp.pretty(F_s)

    # Show the Laplace Transform of the function
    print("Laplace Transform F(s):\n", F_s_pretty)
    
    # Extract the numerator and denominator
    F_s_simplified = sp.simplify(F_s)
    num, den = sp.fraction(F_s_simplified)
    
    # Determine zeros and poles
    zeros = sp.solveset(num, s, domain=sp.S.Complexes)
    poles = sp.solveset(den, s, domain=sp.S.Complexes)
    
    def extract_values(solution_set):
        if isinstance(solution_set, sp.FiniteSet):
            return [f"({round(sp.re(z).evalf(), 5)} {'+' if sp.im(z) >= 0 else '-'} {round(abs(sp.im(z)).evalf(), 5)}j)" for z in solution_set]
        else:
            return []  # Return an empty list if no explicit solutions
    
    zeros_num = extract_values(zeros)
    poles_num = extract_values(poles)
    
    # Show values of zeros and poles
    print("Zeros:", zeros_num)
    print("Poles:", poles_num)
    
    # Convert to numerical values for plotting
    zeros_plot = [(sp.re(z).evalf(), sp.im(z).evalf()) for z in zeros] if isinstance(zeros, sp.FiniteSet) else []
    poles_plot = [(sp.re(p).evalf(), sp.im(p).evalf()) for p in poles] if isinstance(poles, sp.FiniteSet) else []
    
    # Plot zeros and poles
    plt.figure()
    plt.scatter([z[0] for z in zeros_plot], [z[1] for z in zeros_plot], marker='o', color='b', label='Zeros')
    plt.scatter([p[0] for p in poles_plot], [p[1] for p in poles_plot], marker='x', color='r', label='Poles')
    
    # Draw horizontal and vertical axis lines
    plt.axhline(0, color='black', linewidth=0.5)
    plt.axvline(0, color='black', linewidth=0.5)
    
    # Set labels for the axes
    plt.xlabel('Real Part')
    plt.ylabel('Imaginary Part')
    
    # Set the title for the plot
    plt.title(f'S-Domain Plot: Zeros and Poles of Function {i}')
   
    # Add a legend to the plot
    plt.legend()

    # Enable the grid
    plt.grid()

    # Display the plot
    plt.show()
