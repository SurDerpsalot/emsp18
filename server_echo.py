import socket

host = ''
port = 2000
backlog = 5
size = 1024
state = 1

dataxx = []

def parseData(str):
    global state
    count = 0
    seq = 0
    check = 0
    print("Message received: ")
    for x in str:
        if(state == 1): #look for start byte
            if(x == 143): #start byte
                state = 2
        elif(state == 2): #msg type
            if(x == 1):
                print("Type: Post")
                state = 3
            elif(x == 2):
                print("Type: Reply")
                state = 3
            elif(x == 4):
                print("Type: Ack")
                state = 3
            elif(x == 8):
                print("Type: Nack")
                state = 3
            else: #error byte
                print("Error: " + hex(x))
                state = 10
        elif(state == 3): #seq byte
            seq = x
            state = 4
        elif(state == 4): #look for start of text
            if(x == 2): #start of text byte
                state = 5
            else:
                print("Error: " + hex(x))
                state = 10
        elif(state == 5): #get data
            if(count > seq):
                state = 10
            else:
                count = count + 1
            if(x == 3): #end of test byte
                if(count - 1 == seq):
                    state = 6
                else:
                    print("Error: " + hex(x))
                    state = 10
            else:
                int_x = int(x)
                uni_x = chr(int_x)
                dataxx.append(uni_x)
        elif(state == 6): #go to check sum
            print("Checksum:", x)
            check = x
            state = 7
        elif(state == 7): #look for end byte
            if(x == 207):
                print("Data: " + ''.join(dataxx))
                dataxx[:] = []
                state = 8
            else:
                print("Error: " + hex(x))
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
            print("Sending ack...")
            print("")
            client.send(b'*')
        else:
            print("Sending nack...")
            print("")
            client.send(b'`')
        state = 1

client.close()