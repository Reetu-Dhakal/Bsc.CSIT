def gauss_jordan(a, b):
    n = len(b)
    
    # Forward elimination: normalize the pivot row and eliminate other rows
    for i in range(n):
        # Normalize the pivot row (make the diagonal element 1)
        a[i] = [x / a[i][i] for x in a[i]]
        b[i] /= a[i][i]
        
        # Eliminate the i-th column in all other rows
        for j in range(n):
            if i != j:
                ratio = a[j][i]
                a[j] = [a[j][k] - ratio * a[i][k] for k in range(n)]
                b[j] -= ratio * b[i]
    
    return b

# Input: number of variables and the augmented matrix (coefficients and constants)
n = int(input("Enter the number of variables: "))
a = [list(map(float, input(f"Enter row {i + 1} coefficients (space-separated): ").split())) for i in range(n)]
b = list(map(float, input("Enter the constants (space-separated): ").split()))

# Call the Gauss-Jordan method and print the solution
solution = gauss_jordan(a, b)
print("Solution:")
for i in range(n):
    print(f"x{i + 1} = {solution[i]}")
