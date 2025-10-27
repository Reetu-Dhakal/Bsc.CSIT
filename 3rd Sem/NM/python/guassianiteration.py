import math

def f(x): 
    return x ** 2

def gauss_integration(n, a, b):
    if n == 2:
        x = [-1 / math.sqrt(3), 1 / math.sqrt(3)]
        w = [1, 1]
    else:
        raise ValueError("Only n=2 supported here")

    c1 = (b - a) / 2
    c2 = (b + a) / 2
    integral = 0
    for i in range(n):
        integral += w[i] * f(c1 * x[i] + c2)

    return c1 * integral

# Example usage
a, b = 0, 8  # Integration limits
n = 2         # Number of points for Gaussian quadrature (must be 2 here)
result = gauss_integration(n, a, b)
print("Integral:", result)
