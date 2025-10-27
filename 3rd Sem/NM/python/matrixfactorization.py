def lu_decomposition(a, n):
    L = [[0] * n for _ in range(n)]  # Initialize lower triangular matrix L
    U = [[0] * n for _ in range(n)]  # Initialize upper triangular matrix U
    
    # Decompose the matrix 'a' into L and U
    for i in range(n):
        # Set diagonal of L to 1
        L[i][i] = 1
        
        # Upper triangular matrix U
        for j in range(i, n):
            U[i][j] = a[i][j] - sum(L[i][k] * U[k][j] for k in range(i))
        
        # Lower triangular matrix L
        for j in range(i + 1, n):
            L[j][i] = (a[j][i] - sum(L[j][k] * U[k][i] for k in range(i))) / U[i][i]
    
    return L, U

# Input: Matrix size
n = int(input("Enter matrix size: "))

# Input: Matrix 'a' as a list of lists (each row inputted separately)
a = [list(map(float, input(f"Enter row {i+1}: ").split())) for i in range(n)]

# Call LU decomposition
L, U = lu_decomposition(a, n)

# Output: Print L and U matrices
print("L (Lower Triangular Matrix):")
for row in L:
    print(*row)

print("U (Upper Triangular Matrix):")
for row in U:
    print(*row)
