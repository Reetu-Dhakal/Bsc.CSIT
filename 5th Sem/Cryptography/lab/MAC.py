def simple_mac(key: str, message: str) -> int:
    mac = 0
    combined = key + message
    for char in combined:
        mac ^= ord(char)
    return mac

def verify_mac(key: str, message: str, received_mac: int) -> bool:
    return simple_mac(key, message) == received_mac

# Inputs
secret_key = "my_lab_secret_key"
message = "This is a test message for lab."

# Generate MAC
mac_value = simple_mac(secret_key, message)
print(mac_value)

# Verification
received_message = message
received_mac = mac_value

if verify_mac(secret_key, received_message, received_mac):
    print("Message is authentic")
else:
    print("Message has been tampered")
