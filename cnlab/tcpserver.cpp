#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
#define SERV_PORT 2000
using namespace std;
void chat(int connfd)
{
  char buff[80];int n;
  for(;;)
   {
       bzero(buff,sizeof(buff));
       read(connfd,buff,sizeof(buff)); //msg receive from client
       cout<<"From Client :"<<buff<<endl;
       bzero(buff,sizeof(buff));
       
       cout<<"Enter msg send to client :";
       n=0;
       while((buff[n++]=getchar())!='\n');
       write(connfd,buff,sizeof(buff));  
       if((strncmp(buff,"exit",4))==0)
          {
             cout<<"Server Exit\n";
             break;
           }
   }
}
int main(int argc, char **argv)
{
   struct sockaddr_in servaddr,cliaddr;
     int sockfd,connfd,clilen;
     sockfd=socket(AF_INET,SOCK_STREAM,0); 
     if(sockfd ==-1)
     {
        cout<<"Faild to create socket\n";
        return -1;
     }
    cout<<"Socket created successfully\n";
    bzero(&servaddr,sizeof(servaddr));
    
        servaddr.sin_family=AF_INET;
        servaddr.sin_port=htons(SERV_PORT);

	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0) //bind obj to ip
            {
               cout<<"Faild to bind\n";
               return -1;
            }
    
          cout<<"socket successfully binded\n";
          
         if((listen(sockfd,1))!=0)
               {
                       cout<<"Listen failed\n";
                        return -1;
                 }//listen to clients
         cout<<"Listen to client successful\n";

	clilen=sizeof(cliaddr);
	if((connfd=accept(sockfd,(struct sockaddr*)&cliaddr,(socklen_t*)&clilen))< 0)//connect to client
           {
                 cout<<"Faild to connect to client\n";
                  return -1;
            }
           cout<<"client connected\n";

           chat(connfd);
return 0;   
}
