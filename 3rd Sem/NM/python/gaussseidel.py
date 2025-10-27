n = int(input("Enter matrix size: "))  # Number of variables
a = [list(map(float, input(f"Enter row {i + 1}: ").split())) for i in range(n)]  # Coefficient matrix
b = list(map(float, input("Enter RHS values: ").split()))  # Right-hand side values
x = [0] * n  # Initial guess for the solution
tol = 1e-6  # Tolerance level for convergence

while True:
    x_new = x[:]  # Copy of the previous solution
    
    # Iterate through each row and update the solution
    for i in range(n):
        s = sum(a[i][j] * x_new[j] for j in range(n) if j != i)  # Sum of all terms except the diagonal
        x_new[i] = (b[i] - s) / a[i][i]  # Update the i-th value of the solution
    
    # Check for convergence: if the change is smaller than the tolerance, break the loop
    if all(abs(x_new[i] - x[i]) < tol for i in range(n)):
        break
    
    # Update x with the new values for the next iteration
    x = x_new

# Output the solution
print("Solution:", *x)
