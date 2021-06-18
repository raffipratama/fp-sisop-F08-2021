#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <math.h>
#define port 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0;
    int isRoot=0;
    struct sockaddr_in serv_addr;
    int valread;
  
  char buffer[1024];

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    if(getuid() == 0) isRoot = 1;
    send(sock,&isRoot,sizeof(isRoot),0);
    
    while(1){
    valread = read( sock , buffer, 2048);
    printf("%s\n",buffer );
    memset(buffer,0,2048);
    
    }
}
