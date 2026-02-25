from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import hashlib

def pad(msg):
    while len(msg) % 16 != 0: msg += b' '
    return msg

def encrypt(key, msg):
    key = hashlib.sha256(key).digest()[:16]
    return AES.new(key, AES.MODE_ECB).encrypt(pad(msg))

def decrypt(key, ciphertext):
    key = hashlib.sha256(key).digest()[:16]
    return AES.new(key, AES.MODE_ECB).decrypt(ciphertext).rstrip(b' ')

K_A = b'secretA'
K_B = b'secretB'
N1 = b'12345'
K_AB = get_random_bytes(16)

ticket_for_B = encrypt(K_B, pad(K_AB + b"A"))
msg_to_A = encrypt(K_A, pad(K_AB + b"B" + N1) + ticket_for_B)

received = decrypt(K_A, msg_to_A)
session_key = received[:16]
ticket = received[16+len(pad(b"B"+N1)):]
received_by_B = decrypt(K_B, ticket)

print("Session key at B:", received_by_B[:16].hex())
