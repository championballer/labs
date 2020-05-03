import socket
import pickle
from Crypto.Cipher import AES

HOST = '127.0.0.1' # The server's hostname or IP address
PORT = 65432 # The port used by the server

def encrypt(message, key):
	cipher = AES.new(key, AES.MODE_EAX)
	nonce = cipher.nonce
	ciphertext, tag = cipher.encrypt_and_digest(message)
	return [ciphertext, tag, nonce]


message = input("Enter message to be encrypted & sent: ").encode()
key = input("Enter 16-byte AES encryption key: ").encode()

msg = pickle.dumps(encrypt(bytes(message), key))

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST, PORT))
	s.sendall(msg)
	print('Encrypted message sent successfully!')
	data = s.recv(1024)

print('Received', data.decode())