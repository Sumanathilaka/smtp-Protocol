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
  printf("select the server\n");
  fgets(buffer,1024,stdin);

//connect to server to check for the RS is registerd in CS

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7899);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
  send(clientSocket,buffer,1024,0);
  recv(clientSocket, bufferindex,1024, 0);
  printf("%s\n",bufferindex); 
   close(clientSocket);

if(strcmp(bufferindex,"Registerd server. Can Proceed Further")==0){

   
if(strcmp(buffer,"gmail\n")==0)
{

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);



     printf("1.Type 'send' to send a mail .\n");
     printf("2.Type 'inbox' to check the mail.\n");
     printf("3.Type 'signup' to signup with the mails service.\n");
     printf("4.Type 'exit' to logout.\n");

     fgets(bufferindex,1024,stdin);
     send(clientSocket,bufferindex,1024,0);


if(strcmp(bufferindex,"send\n")==0){

        recv(clientSocket, buffer,1024, 0);
         printf("%s\n",buffer);  
        printf("sender mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        printf("password :");
        fgets(buffer,1024,stdin);
       send(clientSocket,buffer,1024,0); 
       recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
             

  if(strcmp(buffer,"Login successful\n")==0)
          {    
        printf("receiver mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            

           if(strcmp(buffer,"receiver found\n")==0)
          {
        printf("Mail :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            
      }
    }
  }

if(strcmp(bufferindex,"inbox\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer); 
    

 if(strcmp(buffer,"Login successful\n")==0)
      {
 recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
}

}

if(strcmp(bufferindex,"signup\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        
       printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
          
}

if(strcmp(bufferindex,"exit\n")==0){

recv(clientSocket, buffer,1024, 0);
      printf("%s\n",buffer);  
    }
}


if(strcmp(buffer,"yahoo\n")==0)
{

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7890);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);



     printf("1.Type 'send' to send a mail .\n");
     printf("2.Type 'inbox' to check the mail.\n");
     printf("3.Type 'signup' to signup with the mails service.\n");
     printf("4.Type 'exit' to logout.\n");

     fgets(bufferindex,1024,stdin);
     send(clientSocket,bufferindex,1024,0);


if(strcmp(bufferindex,"send\n")==0){

        recv(clientSocket, buffer,1024, 0);
         printf("%s\n",buffer);  
        printf("sender mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        printf("password :");
        fgets(buffer,1024,stdin);
       send(clientSocket,buffer,1024,0); 
       recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
             

  if(strcmp(buffer,"Login successful\n")==0)
          {    
        printf("receiver mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            

           if(strcmp(buffer,"receiver found\n")==0)
          {
        printf("Mail :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            
      }
    }
  }

if(strcmp(bufferindex,"inbox\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer); 
    

 if(strcmp(buffer,"Login successful\n")==0)
      {
 recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
}

}

if(strcmp(bufferindex,"signup\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        
       printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
          
}

if(strcmp(bufferindex,"exit\n")==0){

recv(clientSocket, buffer,1024, 0);
      printf("%s\n",buffer);  
    }
}

if(strcmp(buffer,"hotmail\n")==0)
{

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7896);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);



     printf("1.Type 'send' to send a mail .\n");
     printf("2.Type 'inbox' to check the mail.\n");
     printf("3.Type 'signup' to signup with the mails service.\n");
     printf("4.Type 'exit' to logout.\n");

     fgets(bufferindex,1024,stdin);
     send(clientSocket,bufferindex,1024,0);


if(strcmp(bufferindex,"send\n")==0){

        recv(clientSocket, buffer,1024, 0);
         printf("%s\n",buffer);  
        printf("sender mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        printf("password :");
        fgets(buffer,1024,stdin);
       send(clientSocket,buffer,1024,0); 
       recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
             

  if(strcmp(buffer,"Login successful\n")==0)
          {    
        printf("receiver mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            

           if(strcmp(buffer,"receiver found\n")==0)
          {
        printf("Mail :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            
      }
    }
  }

if(strcmp(bufferindex,"inbox\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer); 
    

 if(strcmp(buffer,"Login successful\n")==0)
      {
 recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
}

}

if(strcmp(bufferindex,"signup\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        
       printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
          
}

if(strcmp(bufferindex,"exit\n")==0){

recv(clientSocket, buffer,1024, 0);
      printf("%s\n",buffer);  
    }
}

if(strcmp(buffer,"nitc\n")==0)
{

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7895);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);



     printf("1.Type 'send' to send a mail .\n");
     printf("2.Type 'inbox' to check the mail.\n");
     printf("3.Type 'signup' to signup with the mails service.\n");
     printf("4.Type 'exit' to logout.\n");

     fgets(bufferindex,1024,stdin);
     send(clientSocket,bufferindex,1024,0);


if(strcmp(bufferindex,"send\n")==0){

        recv(clientSocket, buffer,1024, 0);
         printf("%s\n",buffer);  
        printf("sender mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        printf("password :");
        fgets(buffer,1024,stdin);
       send(clientSocket,buffer,1024,0); 
       recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
             

  if(strcmp(buffer,"Login successful\n")==0)
          {    
        printf("receiver mail id :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            

           if(strcmp(buffer,"receiver found\n")==0)
          {
        printf("Mail :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
            
      }
    }
  }

if(strcmp(bufferindex,"inbox\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer); 
    

 if(strcmp(buffer,"Login successful\n")==0)
      {
 recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
}

}

if(strcmp(bufferindex,"signup\n")==0){
recv(clientSocket, buffer,1024, 0);
printf("%s\n",buffer);  
       
 printf("email id:");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
        
       printf("password :");
        fgets(buffer,1024,stdin);
        send(clientSocket,buffer,1024,0); 
        recv(clientSocket, buffer,1024, 0);
        printf("%s\n",buffer);  
          
}

if(strcmp(bufferindex,"exit\n")==0){

recv(clientSocket, buffer,1024, 0);
      printf("%s\n",buffer);  
    }
}


} 


if(strcmp(bufferindex,"Invalid Login")==0){
 printf("The Email Host is not registerd with the server\n");

}

  return 0;
}

