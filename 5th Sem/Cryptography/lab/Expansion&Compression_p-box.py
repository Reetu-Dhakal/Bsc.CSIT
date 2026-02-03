"""
Lab 6: P-box (Permutation Box) - Expansion and Compression
"""

EXPANSION_BOX = [
    32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
]

COMPRESSION_BOX = [
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25
]

def apply_permutation(data, pbox):
    return ''.join(data[i - 1] for i in pbox)

def expand_32_to_48(data_32bit):
    return apply_permutation(data_32bit, EXPANSION_BOX)

def compress_32_to_32(data_32bit):
    return apply_permutation(data_32bit, COMPRESSION_BOX)

def get_binary_input(bits_required):
    data = input(f"Enter {bits_required}-bit binary: ")
    if len(data) != bits_required or any(c not in '01' for c in data):
        print(f"Error: Input must be exactly {bits_required} binary digits (0s and 1s).")
        return None
    return data

def main():
    data = get_binary_input(32)
    if not data:
        return
    expanded = expand_32_to_48(data)
    compressed = compress_32_to_32(data)
    print("\nResults:")
    print(f"Original Input (32 bits):   {data}")
    print(f"Expanded Output (48 bits):  {expanded}")
    print(f"Compressed Output (32 bits): {compressed}")

if __name__ == "__main__":
    main()
