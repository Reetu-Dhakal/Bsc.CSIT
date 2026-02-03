"""
Lab 8: Meet-in-the-Middle Attack on Double DES
"""

def simple_encrypt(plaintext, key):
    """Simple DES-like encryption using XOR"""
    result = 0
    for i in range(16):
        bit = (plaintext >> i) & 1
        key_bit = (key >> i) & 1
        result |= ((bit ^ key_bit) << i)
    return result

def double_des_encrypt(plaintext, key1, key2):
    """Double DES encryption"""
    return simple_encrypt(simple_encrypt(plaintext, key1), key2)

def meet_in_middle_attack(plaintext, ciphertext, key_space):
    """Meet-in-the-Middle Attack"""
    print("\nPlaintext  :", hex(plaintext))
    print("Ciphertext :", hex(ciphertext))
    print("-" * 40)

    # Phase 1: Encrypt plaintext with all K1
    forward_table = {}
    print("Phase 1: Forward encryption")
    for k1 in range(key_space):
        mid = simple_encrypt(plaintext, k1)
        forward_table[mid] = k1

    print("Forward table size:", len(forward_table))

    # Phase 2: Decrypt ciphertext with all K2
    print("\nPhase 2: Backward decryption")
    candidates = []
    for k2 in range(key_space):
        mid = simple_encrypt(ciphertext, k2)
        if mid in forward_table:
            candidates.append((forward_table[mid], k2))

    return candidates

# ---------------- MAIN ---------------- #

print("Meet-in-the-Middle Attack on Double DES")

plaintext = int(input("Enter plaintext (hex): "), 16)
key1 = int(input("Enter Key1 (hex): "), 16)
key2 = int(input("Enter Key2 (hex): "), 16)
key_space = int(input("Enter key space size (e.g. 258): "))

ciphertext = double_des_encrypt(plaintext, key1, key2)

print("\nGenerated Ciphertext:", hex(ciphertext))

candidates = meet_in_middle_attack(plaintext, ciphertext, key_space)

print(f"\nFound {len(candidates)} candidate key pair(s)")
for k1, k2 in candidates:
    print(f"K1 = {hex(k1)}, K2 = {hex(k2)}")
    if double_des_encrypt(plaintext, k1, k2) == ciphertext:
        print("✓ Valid key pair found")
        break