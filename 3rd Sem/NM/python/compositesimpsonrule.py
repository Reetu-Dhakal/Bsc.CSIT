n = int(input("Enter even number of subintervals: "))
a, b = map(float, input("Enter lower and upper limits: ").split())

def f(x):
    return x**2  # Example function

# Check if n is even
if n % 2 != 0:
    raise ValueError("Number of subintervals must be even.")

h = (b - a) / n
s = f(a) + f(b)

for i in range(1, n, 2):
    s += 4 * f(a + i * h)

for i in range(2, n, 2):  # fixed upper limit to n
    s += 2 * f(a + i * h)

print("Integral:", (h / 3) * s)
