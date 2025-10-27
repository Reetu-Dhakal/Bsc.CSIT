def f(x, y): 
    return y - x**2 + 1  # Example function, dy/dx = y - x^2 + 1

def euler_method(x0, y0, h, n):
    x = x0
    y = y0
    print(f"x = {x}, y = {y}")
    
    for i in range(1, n + 1):
        y += h * f(x, y)  # Euler's method update
        x += h
        print(f"x = {x}, y = {y}")

# Get initial values, step size, and number of steps from the user
x0, y0 = map(float, input("Enter initial values x0 and y0: ").split())
h = float(input("Enter step size h: "))
n = int(input("Enter number of steps: "))

# Call the Euler method
euler_method(x0, y0, h, n)
