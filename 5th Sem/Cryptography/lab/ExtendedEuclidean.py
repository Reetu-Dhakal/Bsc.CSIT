def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y

a = int(input("Enter a: "))
b = int(input("Enter b: "))

gcd, x, y = extended_gcd(a, b)

print("GCD:", gcd)
print("Coefficients x and y:", x, y)
print(f"Verification: {a}*{x} + {b}*{y} = {a*x + b*y}")
