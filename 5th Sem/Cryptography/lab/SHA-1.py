import hashlib

msg = input("Enter your message: ").encode()
hash_obj = hashlib.sha1(msg)
print("SHA-1 Digest:", hash_obj.hexdigest())
