#include "socketIO.h"
#include "macro.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <iostream>

using namespace std;

namespace wd
{

SocketIO::SocketIO(int a) : _acceptFd(a) {}

void SocketIO::readN(char* buf, int size)
{
    int total = 0;
    while (total == size) {
        int ret = read(_acceptFd, buf + total, size - total);
        if (-1 == ret) { ERROR_EXIT("read"); }
        total += ret;
    }
}

void SocketIO::writeN(const char* buf, int size)
{
    int total = 0;
    while (total != size) {
        int ret = write(_acceptFd, buf + total, size - total);
        if (-1 == ret) { ERROR_EXIT("write"); }
        total += ret;
    }
}

int SocketIO::readLine(char* buf, int maxlen)
{
    int ret = 0;
    int total = 0;
    int left = maxlen - 1;
    char * p = buf; // 用于指针偏移

    while (left > 0) {
        ret = recvPeek(buf, left);
        for (int i = 0; i < ret; ++i) {
            if (buf[i] == '\n') { // 找到了换行符，可能是第一次，可能是多次以后，但总之找到了
                readN(p, i + 1);
                p += (i + 1);
                total += (i + 1);
                left -= (i + 1);
                *p = '\0';
                return total;
            }
        }
        readN(buf, ret);
        p += ret;
        total += ret;
        left -= ret;
    }
    *p = '\0';
    return total;
}

int SocketIO::recvPeek(char* buf, int size)
{
    int ret = 0;
    do {
        ret = recv(_acceptFd, buf, size, MSG_PEEK);
    } while (-1 == ret && errno == EINTR); // 出现被其它信号打断的情况，之后还去接收
    return ret;
}

}
