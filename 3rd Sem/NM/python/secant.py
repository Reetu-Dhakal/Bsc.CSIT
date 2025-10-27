def f(x): 
    return x**3 - x - 2

def secant(x0, x1, tol=1e-6):
    while abs(f(x1)) > tol:
        x0, x1 = x1, x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
    return x1

# Input the initial guesses x0 and x1
x0, x1 = map(float, input("Enter x0 and x1: ").split())

# Find the root using the Secant method
print("Root:", secant(x0, x1))
