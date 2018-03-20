import socket

host = ''
port = 2000
backlog = 5
size = 1024
state = 1

def parseData(str):
	global state
	count = 0
	seq = 0
	check = 0
	print("received: ")
	for x in str:
		if(state == 1): #look for start byte
			if(x == 143):
				print("START Byte: " + hex(x))
				state = 2
		elif(state == 2): #look for msg type
			if(x == 1):
				print("POST_ Byte: " + hex(x))
				state = 3
			elif(x == 2):
				print("REPL_ Byte: " + hex(x))
				state = 3
			elif(x == 4):
				print("ACKN_ Byte: " + hex(x))
				state = 3
			elif(x == 8):
				print("NACK_ Byte: " + hex(x))
				state = 3
			else:
				print("ERROR Byte: " + hex(x))
				state = 10
		elif(state == 3): #look for seq number
			print("SEQUE Byte: " + hex(x))
			seq = x
			state = 4
		elif(state == 4): #look for start of text
			if(x == 2):
				print("SOTex Byte: " + hex(x))
				state = 5
			else:
				print("ERROR Byte: " + hex(x))
				state = 10
		elif(state == 5): #get data
			if(count > seq):
				state = 10
			else:
				count = count + 1
			if(x == 3): #look for end of text
				if(count == seq):
					print("EOTex Byte: " + hex(x))
					state = 6
				else:
					print("ERROR Byte: " + hex(x))
					state = 10
			else:
				print("DATAX Byte: " + hex(x))
		elif(state == 6): #go to check sum
			print("CHECK Byte: " + hex(x))
			check = x
			state = 7
		elif(state == 7): #look for end
			if(x == 207):
				print("END__ Byte: " + hex(x))
				state = 8
			else:
				print("ERROR Byte: " + hex(x))
				state = 10
		elif (state == 8): #done
			count = 0
			seq = 0
			return True
		else: #error and reset
			state = 1
			count = 0
			seq = 0
			return False
	return False

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host, port))
s.listen(backlog)

print ('server started and listening')

while True:
	client, address = s.accept()
	while True:
		data = client.recv(size)
		if parseData(data):
			print("sending ack...")
			client.send(b'*')
		else:
			print("sending nack...")
			client.send(b'`')
		state = 1

client.close()
