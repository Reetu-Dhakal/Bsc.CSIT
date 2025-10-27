def f(x, y, z): 
    return z  # The first differential equation dy/dx = z

def g(x, y, z): 
    return -y - 2 * z  # The second differential equation dz/dx = -y - 2z

def runge_kutta(x0, y0, z0, h, xn):
    x, y, z = x0, y0, z0
    
    while x < xn:
        # Compute the k-values for Runge-Kutta method
        k1y = h * f(x, y, z)
        k1z = h * g(x, y, z)
        
        k2y = h * f(x + h / 2, y + k1y / 2, z + k1z / 2)
        k2z = h * g(x + h / 2, y + k1y / 2, z + k1z / 2)
        
        k3y = h * f(x + h / 2, y + k2y / 2, z + k2z / 2)
        k3z = h * g(x + h / 2, y + k2y / 2, z + k2z / 2)
        
        k4y = h * f(x + h, y + k3y, z + k3z)
        k4z = h * g(x + h, y + k3y, z + k3z)
        
        # Update y and z using the weighted average of k-values
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6
        z += (k1z + 2 * k2z + 2 * k3z + k4z) / 6
        
        # Move to the next x-value
        x += h
    
    return y, z  # Return both y and z values at xn

# Get user input for initial values, step size, and final x-value
x0, y0 = map(float, input("Enter x0 and y0: ").split())
xn, yn = map(float, input("Enter xn and yn: ").split())  # yn is not really needed
z0 = float(input("Enter initial slope guess: "))
h = float(input("Enter step size h: "))

# Call the Runge-Kutta method
y_final, z_final = runge_kutta(x0, y0, z0, h, xn)

# Output the result
print(f"Computed y({xn}) = {y_final}, z({xn}) = {z_final}")
