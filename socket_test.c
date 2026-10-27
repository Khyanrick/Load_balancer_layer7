#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

//socket creation happening here....
if (server_fd == -1){
    perror("socket connection failed!");
    return 1;
}

printf("\nsocket created successfully\n");

//converting port and ip to binary and storing with the help of the predefined sockaddr_in blueprint
struct  sockaddr_in server_addr = {0};
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);

if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) != 1){
    perror("invalid IP address!");
    close(server_fd);
    return 1;
}

//binding the actual function..
int binding_addr = bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
if (binding_addr == -1){
    perror("bind failed !");
    close(server_fd);
    return 1;
}


//listening....
if (listen(server_fd, 5) == -1){
    perror("listening failed!!");
    close(server_fd);
    return 1;
}

//accept...
int client_fd = accept(server_fd, NULL, NULL);

if (client_fd == -1){
    perror("connection failed !");
    close(server_fd);
    close(client_fd);
    return 1;
}


printf("server is listening on port 8080\n");


close(server_fd); 
return 0;
}
