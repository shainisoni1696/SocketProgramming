#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<iostream>
#define SERV_PORT 2000
using namespace std;
void chat(int sockfd)
{
  char buff[80];int n;
  for(;;)
   {
       bzero(buff,sizeof(buff));
       cout<<"Enter the string :";
       n=0;
       while((buff[n++]=getchar())!='\n');
       write(sockfd,buff,sizeof(buff)); //sending msg to server

       bzero(buff,sizeof(buff));
       read(sockfd,buff,sizeof(buff)); //reply from server
       cout<<"From server: "<<buff<<endl;
       if((strncmp(buff,"exit",4))==0)
          {
             cout<<"Client Exit\n";
             break;
           }
   }
}
int main(int argc, char **argv)
{
   struct sockaddr_in servaddr;
   int sockfd;

   if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)//creating socket object
     {
        cout<<"\n Socket creation error \n";
         return -1;
     }
       cout<<"Socket created successfully!"<<endl;
       bzero(&servaddr,sizeof(servaddr));
       
      servaddr.sin_family=AF_INET;
     servaddr.sin_port=htons(SERV_PORT);

     inet_pton(AF_INET,argv[1],&servaddr.sin_addr);//convert IPV4 To numeric addr 
    
   if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) <0) //connect to server
    {
       cout<<"Failed to connect\n";
        return -1;
     }
    cout<<"Connected to client\n";
   chat(sockfd);   //send message
   close(sockfd);

return 0;   
}
