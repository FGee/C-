#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // 与错误的输出有关
#include <unistd.h>
#include <arpa/inet.h> // 
#include <sys/types.h> // linux 系统编程中接口函数中都需要包含此头文件
#include <sys/socket.h> // linux 网络编程，相关接口函数，需要包含此头文件

int main()
{
    int listenFd;
    listenFd = socket(AF_INET, SOCK_STREAM, 0);

    if (-1 == listenFd) {
        perror("socket");
        exit(EXIT_FAILURE); // 造成一个正常的进程终结并且将EXIT_FAILURE和0377返回至父进程
    }

    // 一个服务器程序,主动关闭后,可以立即重用socket
    int on = 1;
    if ((setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0) {
        perror("setsockopt error");
        close(listenFd);
        exit(EXIT_FAILURE);
    }

    // 实现系统级别的负载均衡，同一时刻，同一个服务器程序可以启动多次
    // 有客户端连接时，系统自动根据各个服务器的负载情况进行分配
    on = 1;
    if ((setsockopt(listenFd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on)))) {
        perror("setsockopt error");
        close(listenFd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // 代表内置的任意网卡，一个服务器往往有多张网卡
    serverAddr.sin_port = htons(8888);

    int ret = bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in));
    if (ret == -1) {
        perror("bind error");
        close(listenFd);
        exit(EXIT_FAILURE);
    }

    ret = listen(listenFd, 10);
    if (ret == -1) {
        perror("listen error");
        close(listenFd);
        exit(EXIT_FAILURE);
    }

    while(1) {
        int peerFd = accept(listenFd, NULL, 0);
        char buf[1024] = "Welcome to server";
        ret = write(peerFd, buf, strlen(buf));
        
        memset(buf, 0, sizeof(buf));
        printf("client data: ");
        ret = read(peerFd, buf, sizeof(buf));
        printf("%s\n", buf);
    }

    close(listenFd);

    return 0;
}

