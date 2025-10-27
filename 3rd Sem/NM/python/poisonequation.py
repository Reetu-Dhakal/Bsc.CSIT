def poisson_eqn(f, dx, dy, max_iter=10000, tol=1e-6):
    rows, cols = len(f), len(f[0])
    phi = [[0.0 for _ in range(cols)] for _ in range(rows)]
    
    for _ in range(max_iter):
        phi_new = [row[:] for row in phi]
        
        # Iterate over the interior grid points
        for i in range(1, rows-1):
            for j in range(1, cols-1):
                phi_new[i][j] = 0.25 * (phi[i+1][j] + phi[i-1][j] + phi[i][j+1] + phi[i][j-1] - dx**2 * dy**2 * f[i][j])
        
        # Check for convergence
        if all(abs(phi_new[i][j] - phi[i][j]) < tol for i in range(rows) for j in range(cols)):
            break
        
        phi = phi_new
    
    return phi

def get_user_input():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    dx = float(input("Enter the grid spacing in x direction (dx): "))
    dy = float(input("Enter the grid spacing in y direction (dy): "))
    
    f = []
    print("Enter the source term (f) values row by row:")
    for i in range(rows):
        row = list(map(float, input(f"Row {i+1}: ").split()))
        if len(row) != cols:
            print(f"Error: Each row must have {cols} elements.")
            return None
        f.append(row)
    
    return f, dx, dy

# Get user input for grid size, spacing, and source term
f, dx, dy = get_user_input()

if f:
    # Solve Poisson equation
    result = poisson_eqn(f, dx, dy)
    print("Solution to Poisson's Equation:")
    for row in result:
        print(row)
