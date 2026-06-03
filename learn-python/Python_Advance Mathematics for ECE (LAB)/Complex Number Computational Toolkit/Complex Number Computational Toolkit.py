"""
Advanced Engineering Mathematics for ECE
Machine Problem No. 1

COMPLEX NUMBER COMPUTATIONAL TOOLKIT: INTEGRATION AND VISUALIZATION WITH PYTHON

Author's Name: Solinap, Charles Hendricks D.
SUbmission Date: March 3, 2025

This program allows users to perform various operations on complex numbers,
convert between different forms (rectangular, polar, exponential), and visualize them on a graph.
It follows PEP 8 guidelines and ensures robustness in handling different input formats.
"""

import os  # Module for operating system commands (clearing terminal screen)
import sys  # Module for system-specific parameters and functions
import cmath  # Module for complex number operations
import math  # Module for trigonometric and logarithmic functions
import matplotlib.pyplot as plt  # Module for plotting complex numbers

# Function to clear the terminal screen for a clean interface
def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear screen based on OS
    sys.stdout.write("\033c")  # Reset terminal display
    sys.stdout.flush()  # Ensure everything is updated

# Function to convert a complex number from rectangular to polar form
def convert_rect_to_polar(z):
    r, theta = abs(z), math.degrees(cmath.phase(z))  # Compute magnitude and angle in degrees
    return r, theta

# Function to convert a complex number from rectangular to exponential form
def convert_rect_to_exponential(z):
    r, theta = convert_rect_to_polar(z)  # Convert to polar first
    return f"{r:.4f}e^(j{theta:.4f}°)"  # Format result in exponential form

# Function to convert a complex number from polar to rectangular form
def convert_polar_to_rect(r, theta):
    theta_rad = math.radians(theta)  # Convert angle to radians
    return cmath.rect(r, theta_rad)  # Convert polar to rectangular form

# Function to convert a complex number from exponential to rectangular form
def convert_exponential_to_rect(r, theta):
    return convert_polar_to_rect(r, theta)  # Uses the same logic as polar-to-rectangular

# Function to plot complex numbers on a 2D graph
def plot_complex_numbers(numbers, labels):
    plt.axhline(0, color='black', linewidth=0.5)  # Draw horizontal axis
    plt.axvline(0, color='black', linewidth=0.5)  # Draw vertical axis
    plt.grid(color='gray', linestyle='--', linewidth=0.5)  # Add grid for reference
    
    for num, label in zip(numbers, labels):  # Loop through numbers and their labels
        plt.scatter(num.real, num.imag, label=label)  # Plot each complex number
        x_offset = 0.5 if num.real >= 0 else -1.5  # Adjust x offset based on position
        y_offset = 0.5 if num.imag >= 0 else -0.5  # Adjust y offset based on position
        plt.text(num.real + x_offset, num.imag + y_offset, f"{label} ({num.real:.2f} + {num.imag:.2f}j)", fontsize=12, ha='left')  # Label each point
    
    plt.xlabel('Real')  # Label x-axis
    plt.ylabel('Imaginary')  # Label y-axis
    plt.title('Complex Number Graph')  # Title for the graph
    plt.legend()  # Show legend for labels
    plt.show()  # Display the plot


# Main function to handle user interaction
def main():
    while True:
        clear_screen()  # Clear the screen before displaying the menu
        print("\nComplex Number Computational Toolkit")
        print("1. Convert Rectangular to Polar")
        print("2. Convert Rectangular to Exponential")
        print("3. Convert Polar to Rectangular/Exponential")
        print("4. Convert Exponential to Rectangular/Polar")
        print("5. Perform Arithmetic Operations")
        print("6. Graph Complex Numbers")
        print("7. Exit")
        choice = input("Select an option (1-7): ")  # Get user choice
        
        if choice == '1':
            z = complex(input("Enter a complex number (a+bj): "))  # Get input in rectangular form
            r, theta = convert_rect_to_polar(z)  # Convert to polar
            print(f"Polar Form: {r:.4f}∠{theta:.4f}°")  # Display result
        
        elif choice == '2':
            z = complex(input("Enter a complex number (a+bj): "))  # Get input in rectangular form
            print(f"Exponential Form: {convert_rect_to_exponential(z)}")  # Convert to exponential form
        
        elif choice == '3':
            r = float(input("Enter magnitude (r): "))  # Get magnitude
            theta = float(input("Enter angle (degrees): "))  # Get angle in degrees
            rect = convert_polar_to_rect(r, theta)  # Convert to rectangular form
            print(f"Rectangular Form: {rect.real:.4f} + {rect.imag:.4f}j")  # Display rectangular form
            print(f"Exponential Form: {r:.4f}e^(j{theta:.4f}°)")  # Display exponential form
        
        elif choice == '4':
            r = float(input("Enter magnitude (r): "))  # Get magnitude
            theta = float(input("Enter angle (degrees): "))  # Get angle in degrees
            rect = convert_exponential_to_rect(r, theta)  # Convert to rectangular form
            print(f"Rectangular Form: {rect.real:.4f} + {rect.imag:.4f}j")  # Display rectangular form
            print(f"Polar Form: {r:.4f}∠{theta:.4f}°")  # Display polar form
        
        elif choice == '5':
            z1 = complex(input("Enter first complex number (a+bj): "))  # Get first number
            z2 = complex(input("Enter second complex number (a+bj): "))  # Get second number
            op = input("Enter operation (+, -, *, /): ")  # Get operation
            if op == '+':
                result = z1 + z2  # Perform addition
            elif op == '-':
                result = z1 - z2  # Perform subtraction
            elif op == '*':
                result = z1 * z2  # Perform multiplication
            elif op == '/':
                result = z1 / z2  # Perform division
            else:
                print("Invalid operation!")  # Handle invalid operations
                continue
            print(f"Result: {result.real:.4f} + {result.imag:.4f}j")  # Display result
            
            # Automatically graph input numbers and result
            plot_complex_numbers([z1, z2, result], ["First Number", "Second Number", "Result"])
        
        elif choice == '6':
            num_count = int(input("Enter the number of complex numbers to plot: "))  # Get number of points
            numbers = []
            labels = []
            for i in range(num_count):
                z = complex(input(f"Enter complex number {i+1} (a+bj): "))  # Get complex number
                label = input(f"Enter label for complex number {i+1}: ")  # Get label for number
                numbers.append(z)  # Store number
                labels.append(label)  # Store label
            plot_complex_numbers(numbers, labels)  # Plot numbers
        
        elif choice == '7':
            print("Exiting program. Goodbye!")
            break  # Exit the program
        
        input("\nPress Enter to continue...")  # Wait for user before refreshing menu

# Entry point of the script
if __name__ == "__main__":
    main()  # Run the program
