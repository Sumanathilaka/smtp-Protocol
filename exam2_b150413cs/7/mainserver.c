/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>




int main(){
  int welcomeSocket, newSocket,childpid,connSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr,serverAddrx;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size,addr_sizex;
int flag1=0;
int flag2=3;
int flag3=3;
char buf1[1024];
char buf2[1024];
char buf3[1024];
char buf4[1024];
char buf5[1024];
char buffer1[1024];
char buffer2[1024];
  
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    
  serverAddr.sin_family = AF_INET;
  
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7899);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

 
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  
  if(listen(welcomeSocket,5)==0)
    printf("Client-side Listening\n");
  else
    printf("Error\n");



  
for ( ; ; ) 
 {
    addr_size = sizeof serverStorage;
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    
    if ( (childpid = fork ()) == 0 ) 
       {
         close(welcomeSocket);

recv(newSocket, buffer,1024, 0);


if(strcmp(buffer,"new")==0){

recv(newSocket, buf4,1024, 0);

FILE* fp;
fp=fopen("mainserver.txt","a");
fputs(buf4,fp);
fclose(fp);

strcpy(buffer,"Added a new email server");
send(newSocket,buffer,1024,0);
flag1=1;
}



if(flag1==0){

FILE* fp;
fp=fopen("mainserver.txt","r");
flag1=0;

while(!feof(fp))
{
fgets(buffer1,1024,fp);
if(strcmp(buffer,buffer1)==0)
{
strcpy(buffer,"Registerd server. Can Proceed Further");
send(newSocket,buffer,1024,0);
flag1=1;
break;
}
}
fclose(fp);

if (flag1==0){
strcpy(buffer,"Invalid Login");
send(newSocket,buffer,1024,0);
}
}

exit(0);
}

close(newSocket);
}

 return 0;
}

