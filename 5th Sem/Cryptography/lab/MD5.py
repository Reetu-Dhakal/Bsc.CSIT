import hashlib

msg = input("Enter your message: ").encode()
hash_obj = hashlib.md5(msg)
print("MD5 Digest:", hash_obj.hexdigest())
