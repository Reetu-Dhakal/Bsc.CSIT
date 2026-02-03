"""
Lab 7: DES (Data Encryption Standard) with Key Generation
"""

PC1 = [57, 49, 41, 33, 25, 17, 9, 1,
       58, 50, 42, 34, 26, 18, 10, 2,
       59, 51, 43, 35, 27, 19, 11, 3,
       60, 52, 44, 36, 28, 20, 12, 4,
       61, 53, 45, 37, 29, 21, 13, 5,
       62, 54, 46, 38, 30, 22, 14, 6,
       63, 55, 47, 39, 31, 23, 15, 7,
       60, 52, 44, 36, 28, 20, 12, 4]

PC2 = [14, 17, 11, 24, 1, 5, 3, 28,
       15, 6, 21, 10, 23, 19, 12, 4,
       26, 8, 16, 7, 27, 20, 13, 2,
       41, 52, 31, 37, 47, 55, 30, 40,
       51, 45, 33, 48, 44, 49, 39, 56,
       34, 53, 46, 42, 50, 36, 29, 32]

ROTATIONS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

def apply_perm(data, perm):
    return ''.join(data[perm[i]-1] for i in range(len(perm)))

def rotate_left(data, n):
    return data[n:] + data[:n]

def generate_subkeys(key):
    key_56 = apply_perm(key, PC1)
    left, right = key_56[:28], key_56[28:]
    subkeys = []
    for i in range(16):
        left = rotate_left(left, ROTATIONS[i])
        right = rotate_left(right, ROTATIONS[i])
        combined = left + right
        subkey = apply_perm(combined, PC2)
        subkeys.append(subkey)
    return subkeys

# ---------------- MAIN ----------------



# Example 64-bit key
example_key = "0000000100000010000000110000010000000101000001100000011100001000"
print("\n 64-bit Key:")
print(example_key)

# Generate 16 subkeys automatically
subkeys = generate_subkeys(example_key)
print("\nGenerated 16 Subkeys:")
for i, k in enumerate(subkeys):
    print(f"K{i+1}: {k}")
