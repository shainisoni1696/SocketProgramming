#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
#define PORT 2000
using namespace std;

int main(int argc, char const *argv[])
{
  char s[80],rec[80];
    fstream file;
    string word;
   int server_fd,new_socket,valread,clilen;
   struct sockaddr_in servaddr,cliaddr;
     
   if((server_fd=socket(AF_INET,SOCK_STREAM,0))==0)
       {
           cout<<"Error";
           exit(0);
        }
     servaddr.sin_family=AF_INET;
     servaddr.sin_addr.s_addr=INADDR_ANY;
     servaddr.sin_port=htons(PORT);

    if(bind(server_fd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
      {
        cout<<"Error occured while binding";
        exit(0);
      }
     if(listen(server_fd,1)<0)
       {
            cout<<"Error";
            exit(0);
        }
      clilen=sizeof(cliaddr);
      if((new_socket=accept(server_fd,(struct sockaddr*)&cliaddr,(socklen_t*)&clilen))<0)
      {
            cout<<"Error";
            exit(0);
       }
         
    cout<<"client connected"<<endl;
   
    string filename="input.txt";
    read(new_socket,rec,80);
    file.open(filename.c_str());

    while(file >> word)
     {
       cout<<word<<end;
       write(new_socket,s,sizeof(s));
     }
close(server_fd);
fclose(fp);
    

return 0;
}
