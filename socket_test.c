#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

if (server_fd == -1){
    perror("socket");
    return 1;
}

printf("socket created successfully !!\n");
printf("socket file descriptor: %d\n", server_fd);

close(server_fd);
return 0;
}
