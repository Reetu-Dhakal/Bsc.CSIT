n = int(input("Enter number of data points: "))
x = list(map(float, input("Enter x values: ").split()))
y = [list(map(float, input(f"Enter y values for x[{i}]: ").split())) for i in range(n)]

h = x[1] - x[0]  # Assuming equally spaced x values

# Creating a new list to store divided differences
div_diff = [y[i][:] for i in range(n)]  # Making a copy of y values to store divided differences

# Calculating divided differences (for all orders)
for j in range(1, n):
    for i in range(n - j):
        div_diff[i].append(div_diff[i + 1][j - 1] - div_diff[i][j - 1])

# First derivative (using first divided difference)
first_derivative = div_diff[0][1] / h

# Second derivative (using second divided difference)
second_derivative = div_diff[0][2] / h**2

# Output the results
print("First Derivative:", first_derivative)
print("Second Derivative:", second_derivative)
