import hashlib

msg = input("Enter your message: ").encode()

sha256_hash = hashlib.sha256(msg).hexdigest()
sha512_hash = hashlib.sha512(msg).hexdigest()

print("SHA-256 Digest:", sha256_hash)
print("SHA-512 Digest:", sha512_hash)
