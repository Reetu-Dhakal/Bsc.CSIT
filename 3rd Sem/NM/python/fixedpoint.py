def g(x): 
    return (x + 2) ** (1/3)

def fixed_point(x0, tol=1e-6):
    while abs(g(x0) - x0) > tol:
        x0 = g(x0)
    return x0

# Input the initial guess
x0 = float(input("Enter initial guess: "))

# Find the root using the Fixed-point iteration method
print("Root:", fixed_point(x0))
