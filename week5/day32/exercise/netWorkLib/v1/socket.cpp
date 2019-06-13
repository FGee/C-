#include "socket.h"
#include "macro.h"

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>

namespace wd
{

Socket::Socket(const int f) : _fd(f) {}

Socket::~Socket()
{
    int ret = close(_fd);
    if (_fd == -1) {
        ERROR_EXIT("close");
    }
}

void Socket::shutDownWrite()
{
    ret = shutdown(_fd, SHUT_WR);
    if (_fd == -1) {
        ERROR_EXIT("shutdown");
    }
}

int Socket::fdGet() const { return _fd; }

}
