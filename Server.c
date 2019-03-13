//Server on Linux 
//Author: Pavan Kumar B N
// Date : 13/03/2019

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <cstdlib>

int main() {
    
  int serverSock=socket(AF_INET, SOCK_STREAM, 0);
	char recv_data[1024];
	struct sockaddr_in servaddr, cliaddr;
	sockaddr_in serverAddr;
	// Initializing socket address structure
	servaddr.sin_port 	= 	htons(5007);
	servaddr.sin_family =	AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
 	socklen_t sin_size=sizeof(struct sockaddr_in);	
	// connecting to the server
	bind(serverSock, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
	// Putting the socket into listening mode
	listen(serverSock,5);
	for(;;)
	{
	  int clientSock= accept(serverSock, (struct sockaddr *) &cliaddr, &sin_size);
	  printf("waiting for data\n");
	  recv(clientSock,recv_data,1024,0);
	  std::cout << "Server received:  " << recv_data << std::endl;
	  close (clientSock);
	}
	return 0;
}
