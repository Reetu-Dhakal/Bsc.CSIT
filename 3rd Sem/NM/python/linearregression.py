# Input x and y values
x = list(map(float, input("Enter x values (space-separated): ").split()))
y = list(map(float, input("Enter y values (space-separated): ").split()))

# Number of data points
n = len(x)

# Means of x and y
x_mean = sum(x) / n
y_mean = sum(y) / n

# Summations needed for the slope (b1)
xy_sum = sum(x[i] * y[i] for i in range(n))
xx_sum = sum(x[i] ** 2 for i in range(n))

# Calculating coefficients
b1 = (xy_sum - n * x_mean * y_mean) / (xx_sum - n * x_mean ** 2)
b0 = y_mean - b1 * x_mean

# Output the equation
print(f"Linear Regression Equation: y = {b0:.4f} + {b1:.4f}x")
