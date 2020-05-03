import socket
import pickle

from Crypto.Cipher import AES

HOST = '127.0.0.1' # Standard loopback interface address (localhost)
PORT = 65432 # Port to listen on (non-privileged ports are > 1023)

def decrypt(data, key):
	data = pickle.loads(data)
	cipher = AES.new(key, AES.MODE_EAX, nonce=data[2])
	plaintext = cipher.decrypt(data[0])
	try:
		cipher.verify(data[1])
		print("\nThe message is authentic!\n\nDecrypted message:",
		plaintext.decode(), "\n")
	except ValueError:
		print("Key incorrect or message corrupted!")
		
key = input("Enter 16-byte AES decryption key: ").encode()
		
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind((HOST, PORT))
	s.listen()
	conn, addr = s.accept()
	with conn:
		print(f"Connection from {addr} has been established.")
		while True:
			data = conn.recv(1024)
			if not data:
				break
			decrypt(data, key)
			conn.sendall(b'ACK')