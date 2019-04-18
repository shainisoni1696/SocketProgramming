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
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr; 
      
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
       cout<<"Faild to create socket\n";
        return -1;
    } 
      
     cout<<"Socket created successfully\n";
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
   // servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    
    
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr)) < 0 ) 
    { 
        cout<<"Faild to bind\n";
               return -1;
    } 
    cout<<"socket successfully binded\n";
    int len, n; 
  
  n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,(socklen_t*)&len); 
    buffer[n] = '\0'; 
   cout<<"from Client :"<<buffer<<endl; 
    cout<<endl;
    sendto(sockfd, (const char *)hello, strlen(hello),  
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,sizeof(cliaddr)); 
    cout<<"Message sent to client"<<endl;
    // close(sockfd); 
    return 0; 
} 
