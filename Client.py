#CLIENT
#Author : Pavan Kumar B N
#Datae : 13/03/2018
#!/usr/bin/env python

import socket

TCP_IP = #'put server ip address / hostname'
TCP_PORT = 5007
BUFFER_SIZE = 1024
MESSAGE = "Hello, There!!"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
s.send(MESSAGE)
data = s.recv(BUFFER_SIZE)
s.close()
print "Sent data:", MESSAGE
