x = list(map(float, input("Enter x values: ").split()))
y = list(map(float, input("Enter y values: ").split()))
h = x[1] - x[0]
fwd_diff = (y[1] - y[0]) / h
bwd_diff = (y[-1] - y[-2]) / h
print("Forward Difference:", fwd_diff)
print("Backward Difference:", bwd_diff)