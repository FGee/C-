#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char ** argv)
{
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    if (clientFd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(struct sockaddr_in));
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr("192.168.198.131");
    //serAddr.sin_addr.s_addr = INADDR_ANY;
    serAddr.sin_port = htons(8888);

    int ret = connect(clientFd, (struct sockaddr*)&serAddr, sizeof(struct sockaddr_in));
    if (-1 == ret) {
        perror("connect error");
        close(clientFd);
        exit(EXIT_FAILURE);
    }

    char buf[1024] = { 0 };
    ret = read(clientFd, buf, sizeof(buf));
    printf("%s\n", buf);

    memset(buf, 0, sizeof(buf));
    ret = read(STDERR_FILENO, buf, sizeof(buf));
    
    ret = write(clientFd, buf, strlen(buf));
    
    memset(buf, 0, sizeof(buf));
    ret = read(clientFd, buf, sizeof(buf));
    printf("%s\n", buf);

    while(1);

    close(clientFd);

    return 0;
}

