#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){
    int server_fd,new_socket;

    struct sockaddr_in address;
    int opt=1;
    int addrlen=sizeof(address);
    char buffer[1024]={0};

    //create socket
    server_fd=socket(AF_INET,SOCK_STREAM,0);

    //bind
    bind(server_fd,(struct sockaddr *)&address,sizeof(address));

    //listen
    listen(server_fd,3);

    //accept connection
    new_socket=accept(server_fd,(struct sockaddr *)&address,(socklen_t*)&addrlen);

    //read data
    read(new_socket,buffer,1024);
    printf("%s\n",buffer);

    //close socket
    close(new_socket);
    close(server_fd);

    return 0;
}