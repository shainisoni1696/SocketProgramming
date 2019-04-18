//sending file to server
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
int  main(int argc,char **argv)
{
int i,j;
ssize_t n;
char filename[80],recline[80];
struct sockaddr_in servaddr;
int sockfd;

sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);

inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

cout<<"Enter the file name :";
cin>>filename;
write(sockfd,filename,sizeof(filename)); //sending filename to server

cout<<"\ndata from server\n";
while(read(sockfd,recline,80)!=0)
{
 fputs(recline,stdout);
}
close(sockfd);
return 0;
}
