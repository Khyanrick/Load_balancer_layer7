#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

if (server_fd == -1){
    perror("socket connection failed!");
    return 1;
}

printf("\nsocket created successfully\n");

struct  sockaddr_in server_addr = {0};
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);

if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) != 1){
    perror("invalid IP address!");
    close(server_fd);
    return 1;
}

int binding_addr = bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
if (binding_addr == -1){
    perror("bind failed !");
    close(server_fd);
    return 1;
}


printf("Socket bound successfully to 127.0.0.1:8000\n");
close(server_fd); 
return 0;
}
