# Get user input
n = int(input("Enter number of subintervals: "))
a, b = map(float, input("Enter lower and upper limits: ").split())

# Define the function to integrate
def f(x):
    return x**2  # Example: f(x) = x^2

# Calculate the width of each subinterval
h = (b - a) / n

# Apply Trapezoidal Rule
s = f(a) + f(b)
for i in range(1, n):
    s += 2 * f(a + i * h)

# Final result
integral = (h / 2) * s
print("Integral:", integral)
