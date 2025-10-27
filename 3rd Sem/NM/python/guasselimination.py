def gauss_elimination(a, b):
    n = len(b)
    
    # Forward elimination: transforming the matrix to upper triangular form
    for i in range(n):
        for j in range(i + 1, n):
            ratio = a[j][i] / a[i][i]
            for k in range(n):
                a[j][k] -= ratio * a[i][k]  # Perform row operations
            b[j] -= ratio * b[i]  # Update constants
    
    # Back substitution: solving the system from the last row to the first
    x = [0 for i in range(n)]
    for i in range(n - 1, -1, -1):
        x[i] = b[i] / a[i][i]  # Calculate the value of x[i]
        for j in range(i - 1, -1, -1):
            b[j] -= a[j][i] * x[i]  # Update constants for the next iteration
    
    return x

# Input: number of variables and the augmented matrix (coefficients and constants)
n = int(input("Enter the number of variables: "))
a = [list(map(float, input(f"Enter row {i + 1} coefficients (space-separated): ").split())) for i in range(n)]
b = list(map(float, input("Enter the constants (space-separated): ").split()))

# Call the Gauss Elimination method and print the solution
solution = gauss_elimination(a, b)
print("Solution:")
for i in range(n):
    print(f"x{i + 1} = {solution[i]}")
