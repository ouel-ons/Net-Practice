#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void)
{
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    /* 1. Create TCP socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        perror("socket");
        return 1;
    }

    /* 2. Configure server address */
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1",
                  &server_addr.sin_addr) != 1)
    {
        perror("inet_pton");
        close(sock_fd);
        return 1;
    }

    /* 3. Connect to server */
    if (connect(sock_fd,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) == -1)
    {
        perror("connect");
        close(sock_fd);
        return 1;
    }

    printf("Connected to server!\n");

    /* 4. Send data */
    send(sock_fd, "Hello from client!\n", 19, 0);

    /* 5. Receive response */
    ssize_t bytes_received = recv(
        sock_fd,
        buffer,
        BUFFER_SIZE - 1,
        0
    );

    if (bytes_received == -1)
    {
        perror("recv");
    }
    else
    {
        buffer[bytes_received] = '\0';
        printf("Server replied: %s", buffer);
    }

    /* 6. Close connection */
    close(sock_fd);

    return 0;
}