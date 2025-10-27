import math

# Input x and y values
x = list(map(float, input("Enter x values (space-separated): ").split()))
y = list(map(float, input("Enter y values (space-separated): ").split()))

n = len(x)

# Transform y values using natural log
log_y = [math.log(val) for val in y]

# Calculate summations
xy_sum = sum(x[i] * log_y[i] for i in range(n))
x_square_sum = sum(x[i] ** 2 for i in range(n))
x_sum = sum(x)
log_y_sum = sum(log_y)

# Calculate slope (b) and intercept (ln(a))
b1 = (n * xy_sum - x_sum * log_y_sum) / (n * x_square_sum - x_sum ** 2)
b0 = (log_y_sum - b1 * x_sum) / n
a = math.exp(b0)

# Display the exponential regression equation
print(f"Exponential Regression Equation: y = {a:.4f} * e^({b1:.4f}x)")
