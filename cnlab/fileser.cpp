// receving file from client and print the data of the file
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
#define SERV_PORT 2000
using namespace std;

int main(int argc, char **argv)
{
 int i,j;
ssize_t n;
FILE *fp;
char s[80],f[80];
struct sockaddr_in servaddr,cliaddr;
int listenfd,connfd,clilen;

listenfd=socket(AF_INET,SOCK_STREAM,0); //create socket object
bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);

bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); //bind obj to ip

listen(listenfd,1);//listen to clients

clilen=sizeof(cliaddr);
connfd=accept(listenfd,(struct sockaddr*)&cliaddr,(socklen_t*)&clilen);//connect to client

cout<<"client connected";
read(connfd,f,80);//read file name
fp=fopen(f,"r");
cout<<"\nname of file is:"<<f<<endl;
while(fgets(s,80,fp)!=NULL) //print data of file
{
  cout<<s;
  write(connfd,s,sizeof(s));//send same data to client
}
close(listenfd);
fclose(fp);

return 0;
}
