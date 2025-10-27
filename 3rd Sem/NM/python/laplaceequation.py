def laplace(n, tol):
    # Initialize the grid with zeros and set boundary conditions
    u = [[0] * n for _ in range(n)]
    for i in range(n):
        u[i][0] = u[i][-1] = u[0][i] = u[-1][i] = 100  # Boundary conditions
    
    err = tol + 1  # Initialize error to be greater than tolerance
    while err > tol:
        err = 0  # Reset error for each iteration
        # Iterate through the grid points (excluding boundaries)
        for i in range(1, n-1):
            for j in range(1, n-1):
                temp = u[i][j]
                # Update the value using the average of the four neighboring points
                u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1])
                # Update the error to track convergence
                err = max(err, abs(temp - u[i][j]))
    
    return u

# Input grid size and tolerance from the user
n = int(input("Enter grid size: "))
tol = float(input("Enter tolerance: "))

# Solve the Laplace equation
res = laplace(n, tol)

# Print the resulting grid
for row in res:
    print(row)
