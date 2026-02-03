"""
Lab 5: S-box (Substitution Box) Implementation (No imports)
"""

# DES S-box S1 (for simplicity)
S_BOX = [
    [14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
    [0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
    [4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
    [15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]
]

def sbox_lookup(input_val):
    """
    Single S-box lookup (6-bit → 4-bit)
    """
    bits = format(input_val, '06b')
    row = int(bits[0] + bits[5], 2)
    col = int(bits[1:5], 2)
    return S_BOX[row][col]


def apply_sbox(input_bits):
    """
    Apply S-box substitution to 48-bit input
    (Compression: 48 → 32 bits)
    """
    output = ""
    for i in range(0, 48, 6):
        block = input_bits[i:i+6]
        row = int(block[0] + block[5], 2)
        col = int(block[1:5], 2)
        val = S_BOX[row][col]
        output += format(val, '04b')
    return output


print("S-box Implementation ")
choice = input("1:Single S-box 2:All S-boxes: ")

if choice == '1':
    x = int(input("Input value (0–63): ")) 
    y = sbox_lookup(x)
    print("Output:", y, "(binary:", format(y, '04b') + ")")

elif choice == '2':
    bits = input("Enter 48-bit binary: ")
    print("Output (32 bits):", apply_sbox(bits))

else:
    print("Invalid")