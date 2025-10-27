# Input values
x = list(map(float, input("Enter x values: ").split()))
y = list(map(float, input("Enter y values: ").split()))

# Step size (assumes equally spaced data)
h = x[1] - x[0]

# Three-point forward and backward differences
fwd_diff = (-3 * y[0] + 4 * y[1] - y[2]) / (2 * h)
bwd_diff = (3 * y[-1] - 4 * y[-2] + y[-3]) / (2 * h)

# Output results
print("Forward Difference:", fwd_diff)
print("Backward Difference:", bwd_diff)
