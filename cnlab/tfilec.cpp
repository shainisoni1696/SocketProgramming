#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<iostream>
#define PORT 2000
using namespace std;
int main(int agrc, char **agrv)
{
  
  struct sockaddr_in servaddr;
   int sockfd;
   char filename[80],recvline[80];
   FILE*fp;
   
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
      {
           cout<<"error";
            return -1;
       }
     cout<<"socket"<<endl;  
     bzero(&servaddr,sizeof(servaddr));
     
      servaddr.sin_family=AF_INET;
      servaddr.sin_port=htons(PORT);

      inet_pton(AF_INET,agrv[1],&servaddr.sin_addr);
     
     connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
       
      cout<<"file name?";
       cin>>filename;
      write(sockfd,filename,sizeof(filename));
    
    while(read(sockfd,recvline,80)!=0)
         {
            fputs(recvline,stdout);
          }
return 0;
}
      
 
