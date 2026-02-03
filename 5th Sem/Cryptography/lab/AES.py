from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_EAX)

plaintext = input("Enter plaintext: ").encode()

ciphertext, tag = cipher.encrypt_and_digest(plaintext)

print("Ciphertext:", ciphertext)

cipher_dec = AES.new(key, AES.MODE_EAX, nonce=cipher.nonce)

try:
    decrypted = cipher_dec.decrypt_and_verify(ciphertext, tag)
    print("Decrypted text:", decrypted.decode())
except ValueError:
    print("Decryption failed! Data may have been tampered.")
