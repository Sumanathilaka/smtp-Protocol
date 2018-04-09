/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

 char buffer[1024],bufferindex[1024]; 
  int clientSocket;
  float a[2];
struct sockaddr_in serverAddr;
  socklen_t addr_size;
   int flagwhile=1;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(7899);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  printf("WELCOME TO CENTRAL SERVER\n");

  strcpy(buffer,"new");
  send(clientSocket,buffer,1024,0);
  printf("add your new server\n");
  fgets(buffer,1024,stdin);

  send(clientSocket,buffer,1024,0);
  recv(clientSocket, bufferindex,1024, 0);
  printf("%s\n",bufferindex); 
  close(clientSocket);


  return 0;
}

