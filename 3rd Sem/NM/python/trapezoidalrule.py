n = int(input("Enter number of intervals: "))
a, b = map(float, input("Enter lower and upper limit: ").split())

def f(x): 
    return x**2  # The function to integrate (x^2)

h = (b - a) / n  # Step size

# Initializing sum with f(a) + f(b)
s = f(a) + f(b)

# Summing up the middle terms (2 * f(x))
for i in range(1, n):
    s += 2 * f(a + i * h)

# Calculating the integral using the Trapezoidal Rule
integral = (h / 2) * s

print("Integral:", integral)
