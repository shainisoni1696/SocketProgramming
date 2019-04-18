#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<iostream>
#define PORT 2000
using namespace std;
int main(int argc, char **argv)
{
 int sockfd,connfd,len;
  struct sockaddr_in servaddr,cliaddr;
  char s[80],f[80];
  FILE *fp;
   
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
      {
           cout<<"error";
            return -1;
       }
     cout<<"socket"<<endl;  
     bzero(&servaddr,sizeof(servaddr));
     
      servaddr.sin_family=AF_INET;
      servaddr.sin_port=htons(PORT);
     
     bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        cout<<"bind"<<endl;
       
     listen(sockfd,1);
       len=sizeof(cliaddr);
      if((connfd=accept(sockfd,(struct sockaddr*)&cliaddr,(socklen_t*)&len))<0)
            {
               cout<<"failed";
                return -1;
             }
        cout<<"success"<<endl;
           
        read(connfd,f,80);
        fp=fopen(f,"r");
        while(fgets(s,80,fp)!=NULL)
             {
                 cout<<s;
                 write(connfd,s,sizeof(s));
              }
        
  
return 0;
}
