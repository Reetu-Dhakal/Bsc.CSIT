def gauss_jordan_inverse(a):
    n = len(a)
    
    # Create the identity matrix I of the same size as a
    I = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    
    # Forward elimination to make a into the identity matrix
    for i in range(n):
        # Normalize the pivot row (make the diagonal element 1)
        a[i] = [x / a[i][i] for x in a[i]]
        I[i] = [x / a[i][i] for x in I[i]]
        
        # Eliminate the i-th column in all other rows
        for j in range(n):
            if i != j:
                ratio = a[j][i]
                a[j] = [a[j][k] - ratio * a[i][k] for k in range(n)]
                I[j] = [I[j][k] - ratio * I[i][k] for k in range(n)]
    
    return I

# Input: the number of rows/columns of the matrix
n = int(input("Enter the number of rows/columns of the matrix: "))

# Input: matrix 'a' as a list of lists (the augmented matrix)
a = [list(map(float, input(f"Enter row {i + 1} (space-separated values): ").split())) for i in range(n)]

# Call the Gauss-Jordan method to find the inverse
inverse = gauss_jordan_inverse(a)

# Output: the inverse matrix
print("Inverse Matrix:")
for row in inverse:
    print(*row)
