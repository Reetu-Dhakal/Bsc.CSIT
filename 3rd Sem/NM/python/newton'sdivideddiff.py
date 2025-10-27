def divided_difference(x, y):
    n = len(x)
    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i])
    return y

# Input values
x = list(map(float, input("Enter x values: ").split()))
y = list(map(float, input("Enter y values: ").split()))
xp = float(input("Enter the point to interpolate: "))

# Compute coefficients
coeffs = divided_difference(x, y.copy())  # Use y.copy() to avoid modifying original y

# Compute the interpolated result
result = coeffs[0]
for i in range(1, len(x)):
    term = coeffs[i]
    for j in range(i):
        term *= (xp - x[j])
    result += term

print("Interpolated value:", result)
