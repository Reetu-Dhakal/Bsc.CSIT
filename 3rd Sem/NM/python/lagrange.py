def lagrange(x, y, xp):
    result = 0
    # Loop through each data point (x_i, y_i)
    for i in range(len(x)):
        term = y[i]
        # Compute the Lagrange basis polynomial for each term
        for j in range(len(x)):
            if j != i:
                term *= (xp - x[j]) / (x[i] - x[j])
        result += term  # Add the term to the result
    return result

# Input the x and y values, as well as the point to interpolate (xp)
x = list(map(float, input("Enter x values: ").split()))
y = list(map(float, input("Enter y values: ").split()))
xp = float(input("Enter the point to interpolate: "))

# Calculate and print the interpolated value at xp
print("Interpolated value:", lagrange(x, y, xp))
