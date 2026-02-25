from Crypto.PublicKey import RSA, DSA
from Crypto.Signature import pkcs1_15, DSS
from Crypto.Hash import SHA256

msg = input("Enter message: ").encode()
h = SHA256.new(msg)

# ===== RSA Digital Signature =====
rsa_key = RSA.generate(2048)
rsa_priv = rsa_key
rsa_pub = rsa_key.publickey()
rsa_sig = pkcs1_15.new(rsa_priv).sign(h)
print("\nRSA Signature:", rsa_sig.hex())
try:
    pkcs1_15.new(rsa_pub).verify(h, rsa_sig)
    print("\nRSA Signature Verified ")
except:
    print("RSA Signature Verification Failed")

# ===== DSS (DSA) Digital Signature =====
dsa_key = DSA.generate(2048)
dsa_priv = dsa_key
dsa_pub = dsa_key.publickey()
dsa_signer = DSS.new(dsa_priv, 'fips-186-3')
dsa_sig = dsa_signer.sign(h)
print("\nDSS Signature:", dsa_sig.hex())
dsa_verifier = DSS.new(dsa_pub, 'fips-186-3')
try:
    dsa_verifier.verify(h, dsa_sig)
    print("\nDSS Signature Verified ")
except:
    print("DSS Signature Verification Failed")
