#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>

#define PORT 4444

int main(){
    
    char msg[254] = "Anon404\n";
    int socket_s = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    bind(socket_s,(struct sockadd*) &server_address,sizeof(server_address));
    
    listen(socket_s,3);
    
    int client;
    client = accept(socket_s,NULL,NULL);
    
    send(client,msg,sizeof(msg),0);
    close(socket_s);
    
    return 0;
}