def u_cal(u, n):
    temp = u
    for i in range(1, n):
        temp *= (u - i)
    return temp

def fact(n):
    f = 1
    for i in range(2, n + 1):
        f *= i
    return f

# Input data
n = 4
x = [45, 50, 55, 60]

# Initialize difference table
y = [[0 for i in range(n)] for j in range(n)]
y[0][0] = 0.7071
y[1][0] = 0.7660
y[2][0] = 0.8192
y[3][0] = 0.8660

# Calculating forward difference table
for i in range(1, n):
    for j in range(n - i):
        y[j][i] = y[j + 1][i - 1] - y[j][i - 1]

# Display difference table
print("Difference Table:")
for i in range(n):
    print(f"{x[i]}\t", end="")
    for j in range(n - i):
        print(f"{y[i][j]:.4f}\t", end="")
    print("")

# Interpolation at a given value
value = 52
u = (value - x[0]) / (x[1] - x[0])
sum = y[0][0]

for i in range(1, n):
    sum += (u_cal(u, i) * y[0][i]) / fact(i)

print(f"\nValue at {value} is {round(sum, 6)}")
