def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

if gcd(a, b) == 1:
    print(f"{a} and {b} are co-prime ")
else:
    print(f"{a} and {b} are not co-prime ")
