# Get user input
n = int(input("Enter even number of subintervals: "))
a, b = map(float, input("Enter lower and upper limits: ").split())

# Check that n is even
if n % 2 != 0:
    raise ValueError("Number of subintervals must be even for Simpson's 1/3 Rule.")

# Define the function to integrate
def f(x):
    return x**2  # Example function

# Calculate subinterval width
h = (b - a) / n

# Apply Simpson's 1/3 Rule
s = f(a) + f(b)

# Add 4*f(x) for odd indices
for i in range(1, n, 2):
    s += 4 * f(a + i * h)

# Add 2*f(x) for even indices
for i in range(2, n, 2):
    s += 2 * f(a + i * h)

# Final result
integral = (h / 3) * s
print("Integral:", integral)
