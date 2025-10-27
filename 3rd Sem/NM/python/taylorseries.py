def f(x, y): 
    return y - x ** 2 + 1  # The first derivative function y' = f(x, y)

def f_prime(x, y): 
    return 2 * x - 2 * y  # The second derivative function y'' (Assumed form)

def taylor_series_method(x0, y0, h, n):
    x = x0
    y = y0
    print(f"x = {x}, y = {y}")
    
    for i in range(1, n + 1):
        y_prime = f(x, y)  # First derivative (y')
        y_double_prime = f_prime(x, y)  # Second derivative (y'')
        
        # Taylor series method update
        y += h * y_prime + (h ** 2 / 2) * y_double_prime
        x += h
        
        print(f"x = {x}, y = {y}")

# Get initial values, step size, and number of steps from the user
x0, y0 = map(float, input("Enter initial values x0 and y0: ").split())
h = float(input("Enter step size h: "))
n = int(input("Enter number of steps: "))

# Call the Taylor Series method
taylor_series_method(x0, y0, h, n)
