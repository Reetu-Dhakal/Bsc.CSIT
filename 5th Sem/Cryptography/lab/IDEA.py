MOD = 65536
MOD_INV = 65537

def mul(a, b):
    if a == 0: a = MOD_INV
    if b == 0: b = MOD_INV
    r = (a * b) % MOD_INV
    return 0 if r == MOD_INV else r

def add(a, b):
    return (a + b) % MOD

def sub(a, b):
    return (a - b) % MOD

def mul_inv(x):
    if x == 0:
        return 0
    return pow(x, -1, MOD_INV)
    
def idea_encrypt(block, k):
    x1, x2, x3, x4 = block

    x1 = mul(x1, k[0])
    x2 = add(x2, k[1])
    x3 = add(x3, k[2])
    x4 = mul(x4, k[3])

    t1 = x1 ^ x3
    t2 = x2 ^ x4

    t1 = mul(t1, k[4])
    t2 = add(t2, t1)
    t2 = mul(t2, k[5])
    t1 = add(t1, t2)

    y1 = x1 ^ t2
    y2 = x3 ^ t2
    y3 = x2 ^ t1
    y4 = x4 ^ t1

    return y1, y3, y2, y4  # swap

# ---------- DECRYPT ----------
def idea_decrypt(block, k):
    y1, y2, y3, y4 = block
    y2, y3 = y3, y2  # reverse swap

    t1 = y1 ^ y2
    t2 = y3 ^ y4

    t1 = mul(t1, k[4])
    t2 = add(t2, t1)
    t2 = mul(t2, k[5])
    t1 = add(t1, t2)

    x1 = y1 ^ t2
    x3 = y2 ^ t2
    x2 = y3 ^ t1
    x4 = y4 ^ t1

    x1 = mul(x1, mul_inv(k[0]))
    x2 = sub(x2, k[1])
    x3 = sub(x3, k[2])
    x4 = mul(x4, mul_inv(k[3]))

    return x1, x2, x3, x4

# ---------- MAIN ----------
print("Enter 4 values (0–65535) for plaintext:")
p = (
    int(input("X1 (0-65535): ")),
    int(input("X2 (0-65535): ")),
    int(input("X3 (0-65535): ")),
    int(input("X4 (0-65535): "))
)

key = [1, 2, 3, 4, 5, 6]

cipher = idea_encrypt(p, key)
print("Ciphertext:", cipher)

plain = idea_decrypt(cipher, key)
print("Decrypted text:", plain)