def f(x): 
    return x**2  # The function to integrate

def romberg_integration(a, b, tol=1e-6):
    n = 1
    R = [[0.5 * (b - a) * (f(a) + f(b))]]  # First step of Romberg integration
    while True:
        h = (b - a) / n
        sum = 0
        for i in range(1, n, 2):  # Sum over the odd indices
            sum += f(a + i * h)
        R_new = 0.5 * R[n-1][0] + h * sum  # Calculate the next R value
        R.append([R_new])
        
        # Richardson extrapolation
        for m in range(1, len(R[0])):
            R[n].append((4**m * R[n][m-1] - R[n-1][m-1]) / (4**m - 1))
        
        # Check for convergence
        if abs(R[n][-1] - R[n-1][-1]) < tol:
            break
        
        n *= 2  # Double the number of subintervals
        
    return R[n][-1]  # Return the final estimate

# Get the limits from the user
a, b = map(float, input("Enter lower and upper limits: ").split())

# Perform Romberg integration
result = romberg_integration(a, b)

# Output the result
print("Integral:", result)
