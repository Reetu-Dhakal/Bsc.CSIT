n = int(input("Enter multiple of 3 for subintervals: "))
a, b = map(float, input("Enter lower and upper limits: ").split())

def f(x): 
    return x**2

h = (b - a) / n
s = f(a) + f(b)

# Adding contributions for every third subinterval
for i in range(1, n, 3):
    s += 3 * f(a + i * h)

# Adding contributions for the second type of subintervals (every third one starting from 2)
for i in range(2, n - 1, 3):
    s += 3 * f(a + i * h)

# Adding contributions for the third type of subintervals (every third one starting from 3)
for i in range(3, n - 2, 3):
    s += 2 * f(a + i * h)

# Final result
print("Integral:", (3 * h / 8) * s)
