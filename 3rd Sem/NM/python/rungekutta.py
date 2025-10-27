def f(x, y): 
    return y - x**2 + 1  # Example function, dy/dx = y - x^2 + 1

def runge_kutta(x0, y0, h, n):
    x = x0
    y = y0
    print(f"x = {x}, y = {y}")
    
    for i in range(n):
        k1 = h * f(x, y)
        k2 = h * f(x + h / 2, y + k1 / 2)
        k3 = h * f(x + h / 2, y + k2 / 2)
        k4 = h * f(x + h, y + k3)
        
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6  # Update y using the weighted average of k1, k2, k3, and k4
        x += h  # Move to the next step
        
        print(f"x = {x}, y = {y}")

# Get initial values, step size, and number of steps from the user
x0, y0 = map(float, input("Enter initial values x0 and y0: ").split())
h = float(input("Enter step size h: "))
n = int(input("Enter number of steps: "))

# Call the Runge-Kutta method
runge_kutta(x0, y0, h, n)
