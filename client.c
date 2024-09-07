#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<unistd.h>

#define PORT 4444

int main(){

    char msg[254];
    int n_socket = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET ;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int status;
    status = connect(n_socket,(struct sockaddr*)&server_address,sizeof(
server_address));
    if (status == -1){
        printf("Connection error\n");
        exit(0);
    }

    recv(n_socket,msg,sizeof(msg),0);
    printf("the msg is %s\n",msg);
    close(n_socket);

    return 0;
}