def caesar_cipher_encrypt(text, key):
    result = ""
    for char in text:
        if char.isalpha():
            if char.islower():
                result += chr((ord(char) - ord('a') + key) % 26 + ord('a'))
            else:
                result += chr((ord(char) - ord('A') + key) % 26 + ord('A'))
        else:
            result += char
    return result

# Input
text = input("Enter text: ")
key = int(input("Enter key (shift): "))

    # Encryption
encrypted_text = caesar_cipher_encrypt(text, key)
print("Encrypted text:", encrypted_text)


def caesar_cipher_decrypt(text, key):
    result = ""
    for char in text:
        if char.isalpha():
            if char.islower():
                result += chr((ord(char) - ord('a') - key) % 26 + ord('a'))
            else:
                result += chr((ord(char) - ord('A') - key) % 26 + ord('A'))
        else:
            result += char
    return result

# Decryption
decrypted_text = caesar_cipher_decrypt(encrypted_text, key)
print("Decrypted text:", decrypted_text)
