#include "socketIO.h"
#include "macro.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

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
    while (total == size) {
        int ret = write(_acceptFd, buf + total, size - total);
        if (-1 == ret) { ERROR_EXIT("write"); }
        total += ret;
    }
}

void SocketIO::readLine(char* buf, int size)
{
    
}

}
