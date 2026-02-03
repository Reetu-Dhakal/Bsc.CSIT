def mod_inverse(a, m):
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        gcd_val, x1, y1 = extended_gcd(b % a, a)
        x = y1 - (b // a) * x1
        return gcd_val, x, x1

    gcd_val, x, _ = extended_gcd(a % m, m)
    if gcd_val != 1:
        return None
    return x % m


def hill_encrypt(plaintext, key):
    plaintext = plaintext.upper().replace(" ", "")
    if len(plaintext) % 2 != 0:
        plaintext += 'X'

    ciphertext = ""

    for i in range(0, len(plaintext), 2):
        x1 = ord(plaintext[i]) - ord('A')
        x2 = ord(plaintext[i + 1]) - ord('A')

        y1 = (key[0][0] * x1 + key[0][1] * x2) % 26
        y2 = (key[1][0] * x1 + key[1][1] * x2) % 26

        ciphertext += chr(y1 + ord('A')) + chr(y2 + ord('A'))

    return ciphertext


def hill_decrypt(ciphertext, key):
    ciphertext = ciphertext.upper().replace(" ", "")
    plaintext = ""

    det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26
    det_inv = mod_inverse(det, 26)

    if det_inv is None:
        return "Key matrix is not invertible"

    inv_key = [
        [(key[1][1] * det_inv) % 26, (-key[0][1] * det_inv) % 26],
        [(-key[1][0] * det_inv) % 26, (key[0][0] * det_inv) % 26]
    ]

    for i in range(0, len(ciphertext), 2):
        y1 = ord(ciphertext[i]) - ord('A')
        y2 = ord(ciphertext[i + 1]) - ord('A')

        x1 = (inv_key[0][0] * y1 + inv_key[0][1] * y2) % 26
        x2 = (inv_key[1][0] * y1 + inv_key[1][1] * y2) % 26

        plaintext += chr(x1 + ord('A')) + chr(x2 + ord('A'))

    return plaintext


key_matrix = [[1, 2], [3, 5]]

text = input("Enter plaintext: ")

encrypted = hill_encrypt(text, key_matrix)
decrypted = hill_decrypt(encrypted, key_matrix)

print("Encrypted text:", encrypted)
print("Decrypted text:", decrypted)
