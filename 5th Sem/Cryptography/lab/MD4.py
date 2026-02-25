from Crypto.Hash import MD4

msg = input("Enter your message: ").encode()
hash_obj = MD4.new(msg)
print("MD4 Digest:", hash_obj.hexdigest())
