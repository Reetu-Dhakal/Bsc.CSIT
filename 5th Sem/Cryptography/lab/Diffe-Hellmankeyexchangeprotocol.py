p = int(input("Enter prime number (p): "))
g = int(input("Enter primitive root (g): "))

a = int(input("Enter private key of Alice: "))
b = int(input("Enter private key of Bob: "))

A = pow(g, a, p)
B = pow(g, b, p)

print("Public key of Alice:", A)
print("Public key of Bob:", B)

key_alice = pow(B, a, p)
key_bob = pow(A, b, p)

print("Shared key computed by Alice:", key_alice)
print("Shared key computed by Bob:", key_bob)
