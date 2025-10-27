def f(x):
    return x**3 - x - 2

def bisection(a, b, tol=1e-6):
    while abs(b - a) > tol:
        c = (a + b) / 2
        if f(c) == 0:
            return c
        (a, b) = (c, b) if f(a) * f(c) < 0 else (a, c)
    return (a + b) / 2

# Input the interval [a, b]
a, b = map(float, input("Enter a and b: ").split())

# Print the root of the equation
print("Root:", bisection(a, b))
