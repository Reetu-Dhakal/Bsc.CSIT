def horner(coefficients, x):
    result = coefficients[0]
    for i in range(1, len(coefficients)):
        result = result * x + coefficients[i]
    return result

# Example: Evaluate polynomial 3x^3 + 2x^2 - x + 5 at x = 2
coefficients = [2, -6 , 2, -1]
x = float(input("Enter the value of x: "))
result = horner(coefficients, x)
print(f"Result of polynomial evaluation: {result}")
