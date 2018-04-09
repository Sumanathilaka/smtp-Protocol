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
int flag1=3;
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
  serverAddr.sin_port = htons(7891);
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

if(strcmp(buffer,"signup\n")==0){
            
 strcpy(buffer,"welcome to sign-up.\n");
 send(newSocket,buffer,1024,0); 
 recv(newSocket, buffer,1024, 0);
  strcpy(buf2,buffer);
 strcpy(buffer,"Email verified\n");
 send(newSocket,buffer,1024,0); 
 recv(newSocket, buffer,1024, 0);
 strcpy(buf1,buffer);
 strcpy(buffer,"Password verified\n");
 send(newSocket,buffer,1024,0); 

   FILE* fp;
fp=fopen("registergmail.txt","a");
fputs(buf2,fp);
fputs(buf1,fp);
fclose(fp);
}

if(strcmp(buffer,"inbox\n")==0){
 strcpy(buffer,"welcome to FTP- Inbox\n");
 send(newSocket,buffer,1024,0); 

 recv(newSocket, buffer,1024, 0);
 strcpy(buf1,buffer);
 strcpy(buffer,"Email received\n");
 send(newSocket,buffer,1024,0); 
 recv(newSocket, buffer,1024, 0);
 strcpy(buf2,buffer);
 strcpy(buffer,"Password received\n");
 send(newSocket,buffer,1024,0); 

FILE* fp;
fp=fopen("registergmail.txt","r");
flag1=0;


while(!feof(fp))
{
fgets(buffer1,1024,fp);
fgets(buffer2,1024,fp);

if(strcmp(buf1,buffer1)==0 && strcmp(buf2,buffer2)==0)
{
strcpy(buffer,"Login successful\n");
send(newSocket,buffer,1024,0);


FILE *fp;char c;int index=0;
  fp=fopen(buf1,"r");
  while((c=fgetc(fp))!=EOF)
             
       buffer[index++]=c;
       buffer[index]='\0';

 send(newSocket,buffer,1024,0);
flag1=1;
break;
}
}

if (flag1==0){
strcpy(buffer,"Invalid Login");
send(newSocket,buffer,1024,0);
}

}

if(strcmp(buffer,"exit\n")==0){
            
 strcpy(buffer,"Thank for joining with us.\n");
 send(newSocket,buffer,1024,0); 
}

if(strcmp(buffer,"send\n")==0){
            
 strcpy(buffer,"welcome to mail server,\n");
 send(newSocket,buffer,1024,0); 
 recv(newSocket, buffer,1024, 0);
 strcpy(buf1,buffer);
 recv(newSocket, buffer,1024, 0);
 strcpy(buf2,buffer);

FILE* fp;
fp=fopen("registergmail.txt","r");
flag1=0;
while(!feof(fp))
{
fgets(buffer1,1024,fp);
fgets(buffer2,1024,fp);

if(strcmp(buf1,buffer1)==0 && strcmp(buf2,buffer2)==0)
{
strcpy(buffer,"Login successful\n");
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

if (flag1==1){
   recv(newSocket, buffer,1024, 0);
   strcpy(buf3,buffer);

FILE* fp;
fp=fopen("registergmail.txt","r");
flag2=0;
while(!feof(fp))
{
fgets(buffer1,1024,fp);
fgets(buffer2,1024,fp);

if(strcmp(buf3,buffer1)==0 )
{
strcpy(buffer,"receiver found\n");
send(newSocket,buffer,1024,0);
flag2=1;
break;
}
}
fclose(fp);
}

if (flag2==0){
fp=fopen("registeryahoo.txt","r");
flag2=0;
while(!feof(fp))
{
fgets(buffer1,1024,fp);
fgets(buffer2,1024,fp);

if(strcmp(buf3,buffer1)==0 )
{
strcpy(buffer,"receiver found\n");
send(newSocket,buffer,1024,0);
flag2=1;
break;
}
}
fclose(fp);
}



if (flag2==0){
strcpy(buffer,"receiver not found");
send(newSocket,buffer,1024,0);
}

if (flag2==1){
   recv(newSocket, buffer,1024, 0);
   strcpy(buf4,buffer);

 FILE* fp;
fp=fopen(buf3,"a");
fputs(buf1,fp);
fputs(buf4,fp);
fclose(fp);

strcpy(buffer,"Msg sent");
send(newSocket,buffer,1024,0);

}
}



exit(0);
}

close(newSocket);
}

 return 0;
}

