def forward_difference(x, y, xp):
    n = len(x)
    
    # Initialize difference table with first row as y values
    diff_table = [y[:]]  # Copy y values

    # Build the forward difference table
    for i in range(1, n):
        row = []
        for j in range(n - i):
            value = diff_table[i - 1][j + 1] - diff_table[i - 1][j]
            row.append(value)
        diff_table.append(row)

    # Newton's Forward Interpolation formula
    result = y[0]
    h = x[1] - x[0]  # assuming equal intervals
    p = (xp - x[0]) / h
    term = 1

    for i in range(1, n):
        term *= (p - (i - 1)) / i
        result += term * diff_table[i][0]

    return result

# Input and Output
x = list(map(float, input("Enter x values: ").split()))
y = list(map(float, input("Enter y values: ").split()))
xp = float(input("Enter the point to interpolate: "))

print("Interpolated value:", forward_difference(x, y, xp))
