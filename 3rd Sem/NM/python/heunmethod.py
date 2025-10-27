def f(x, y): 
    return y - x**2 + 1  # Example function, dy/dx = y - x^2 + 1

def heun_method(x0, y0, h, n):
    x = x0
    y = y0
    print(f"x = {x}, y = {y}")
    
    for i in range(1, n + 1):
        # Predictor step (Euler's method)
        y_predictor = y + h * f(x, y)
        
        # Corrector step (Heun's method)
        y_corrector = y + (h / 2) * (f(x, y) + f(x + h, y_predictor))
        
        # Update y with the corrected value
        y = y_corrector
        x += h
        print(f"x = {x}, y = {y}")

# Get initial values, step size, and number of steps from the user
x0, y0 = map(float, input("Enter initial values x0 and y0: ").split())
h = float(input("Enter step size h: "))
n = int(input("Enter number of steps: "))

# Call the Heun method
heun_method(x0, y0, h, n)
