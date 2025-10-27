def poly_regression(x, y, degree):
    n = len(x)
    
    # Create the X matrix with powers of x
    X = [[x[i]**j for j in range(degree + 1)] for i in range(n)]
    
    # Matrix multiplication function
    def mat_mult(A, B):
        return [
            [sum(A[i][k] * B[k][j] for k in range(len(B))) for j in range(len(B[0]))] 
            for i in range(len(A))
        ]
    
    # Matrix transpose function
    def transpose(M):
        return [[M[j][i] for j in range(len(M))] for i in range(len(M[0]))]
    
    # Matrix inversion function using Gaussian elimination
    def inverse(M):
        n = len(M)
        Augmented = [M[i] + [1 if i == j else 0 for j in range(n)] for i in range(n)]
        
        # Perform row operations to convert M into an identity matrix
        for i in range(n):
            if Augmented[i][i] == 0:
                for j in range(i + 1, n):
                    if Augmented[j][i] != 0:
                        Augmented[i], Augmented[j] = Augmented[j], Augmented[i]
                        break
            
            # Normalize the pivot row
            factor = Augmented[i][i]
            for j in range(2 * n):
                Augmented[i][j] /= factor
            
            # Eliminate other rows
            for j in range(n):
                if j != i:
                    factor = Augmented[j][i]
                    for k in range(2 * n):
                        Augmented[j][k] -= Augmented[i][k] * factor
        
        # Extract the inverse matrix
        return [row[n:] for row in Augmented]

    # Perform matrix operations to find the coefficients
    Xt = transpose(X)
    XtX = mat_mult(Xt, X)
    XtX_inv = inverse(XtX)
    XtY = mat_mult(Xt, [[y[i]] for i in range(n)])

    # Extract the coefficients from the result of the matrix multiplication
    coeff = [coeff[0] for coeff in mat_mult(XtX_inv, XtY)]
    return coeff

# Input degree and data points
degree = int(input("Enter the degree of the polynomial: "))
x = list(map(float, input("Enter the x values (space-separated): ").split()))
y = list(map(float, input("Enter the y values (space-separated): ").split()))

# Get the polynomial coefficients
coeff = poly_regression(x, y, degree)

# Output the polynomial regression equation
print("Polynomial Regression Equation: ", end="")
print(" + ".join([f"{coeff[i]:.6f}x^{i}" if i > 0 else f"{coeff[i]:.6f}" for i in range(degree + 1)]))
