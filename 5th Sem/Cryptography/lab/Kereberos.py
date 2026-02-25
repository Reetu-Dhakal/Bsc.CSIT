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

# Shared secrets with KDC
K_A = b'secretA'
K_S = b'secretServer'

# Step 1: A requests ticket for server from KDC
N1 = b'12345'
K_TGS = get_random_bytes(16)  # session key for A->Server

ticket_for_S = encrypt(K_S, K_TGS + b"A")
msg_to_A = encrypt(K_A, K_TGS + ticket_for_S)

# Step 2: A decrypts message from KDC
received = decrypt(K_A, msg_to_A)
session_key = received[:16]
ticket = received[16:]

# Step 3: A sends ticket to Server
received_by_S = decrypt(K_S, ticket)
server_session_key = received_by_S[:16]

print("Session key at Server:", server_session_key.hex())
