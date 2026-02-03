def generate_key_matrix(key):
    key = key.upper().replace("J", "I")
    matrix = []
    for char in key:
        if char.isalpha() and char not in matrix:
            matrix.append(char)
    for char in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if char not in matrix:
            matrix.append(char)
    return [matrix[i:i+5] for i in range(0, 25, 5)]


def prepare_text(text):
    text = text.upper().replace("J", "I").replace(" ", "")
    prepared = ""
    i = 0
    while i < len(text):
        a = text[i]
        b = text[i + 1] if i + 1 < len(text) else ''
        if a == b:
            prepared += a + 'X'
            i += 1
        else:
            prepared += a
            if b:
                prepared += b
                i += 2
            else:
                i += 1
    if len(prepared) % 2 != 0:
        prepared += 'X'
    return prepared


def find_position(matrix, char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j
    return None


def playfair_encrypt(text, key):
    matrix = generate_key_matrix(key)
    text = prepare_text(text)
    cipher = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i+1]
        r1, c1 = find_position(matrix, a)
        r2, c2 = find_position(matrix, b)

        if r1 == r2:
            cipher += matrix[r1][(c1 + 1) % 5]
            cipher += matrix[r2][(c2 + 1) % 5]
        elif c1 == c2:
            cipher += matrix[(r1 + 1) % 5][c1]
            cipher += matrix[(r2 + 1) % 5][c2]
        else:
            cipher += matrix[r1][c2]
            cipher += matrix[r2][c1]

    return cipher


def playfair_decrypt(cipher, key):
    matrix = generate_key_matrix(key)
    cipher = cipher.upper().replace(" ", "")
    plain = ""

    for i in range(0, len(cipher), 2):
        a, b = cipher[i], cipher[i+1]
        r1, c1 = find_position(matrix, a)
        r2, c2 = find_position(matrix, b)

        if r1 == r2:
            plain += matrix[r1][(c1 - 1) % 5]
            plain += matrix[r2][(c2 - 1) % 5]
        elif c1 == c2:
            plain += matrix[(r1 - 1) % 5][c1]
            plain += matrix[(r2 - 1) % 5][c2]
        else:
            plain += matrix[r1][c2]
            plain += matrix[r2][c1]

    return plain


key = input("Enter key: ")
text = input("Enter plaintext: ")

encrypted = playfair_encrypt(text, key)
decrypted = playfair_decrypt(encrypted, key)

print("Encrypted text:", encrypted)
print("Decrypted text:", decrypted)
