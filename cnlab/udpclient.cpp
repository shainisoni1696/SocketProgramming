// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include<iostream>
#define PORT 2000 
#define MAXLINE 1024
using namespace std;
 
// Driver code 
int main(int agrc,char **argv) { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
          cout<<"socket failed"<<endl;
           return -1;
    } 
    cout<<"socket made successfully\n";
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
   // servaddr.sin_addr.s_addr = INADDR_ANY; 
      
   
     inet_pton(AF_INET,argv[1],&servaddr.sin_addr);//convert IPV4 To numeric addr 
    
    int n, len; 
      
    sendto(sockfd, (const char *)hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
    cout<<"message sent to server\n\n"; 
          
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr,(socklen_t*)&len); 
    buffer[n] = '\0'; 
     cout<<"from server:"<<buffer<<endl;
    close(sockfd); 
    return 0; 
} 
