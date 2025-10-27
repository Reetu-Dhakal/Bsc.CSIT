def main():
    # Input number of data points
    n = int(input("Enter number of data points: "))

    # Input x values
    x = list(map(float, input("Enter x values: ").split()))

    # Initialize 2D list for difference table
    y = []
    print("Enter y values:")
    for i in range(n):
        row = list(map(float, input(f"For x[{i}]: ").split()))
        # Fill the rest of the row with zeros to hold future differences
        row += [0] * (n - len(row))
        y.append(row)

    # Step size (assumes equally spaced)
    h = x[1] - x[0]

    # Create backward difference table
    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1]

    # Calculate first and second derivative at last point
    b1 = y[n - 1][1] / h
    b2 = (y[n - 1][1] - y[n - 1][2] / 2) / h

    # Output
    print(f"First Derivative: {b1:.6f}")
    print(f"Second Derivative: {b2:.6f}")

# Run the main function
main()
