def f(x): 
    return x**3 - x - 2

def df(x): 
    return 3*x**2 - 1

def newton(x, tol=1e-6):
    while abs(f(x)) > tol:
        x -= f(x) / df(x)
    return x

# Input initial guess
x = float(input("Enter initial guess: "))

# Find the root using Newton's method
print("Root:", newton(x))
