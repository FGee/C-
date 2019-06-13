#include "acceptor.h"
#include "macro.h"

#include <sys/types.h>
#include <sys/socket.h>

namespace wd
{

Acceptor::Acceptor(const string& ip, const unsigned short& port)
    : _inetAddr(ip, port), _listenFd(socket()) {}

int Acceptor::socket() 
{
    int listenFdTmp = ::socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == listenFdTmp) { ERROR_EXIT("socket"); }
    return listenFdTmp;
}

int Acceptor::listenFdGet() const { return _listenFd.fdGet(); }

void Acceptor::setReuseAddr()
{
    int on = 1;
    int ret = setsockopt(_listenFd.fdGet(), SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if (-1 == ret) { ERROR_EXIT("setsockopt"); }
}

void Acceptor::setReusePort()
{
    int on = 1;
    int ret = setsockopt(_listenFd.fdGet(), SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));
    if (-1 == ret) { ERROR_EXIT("setsockopt"); }
}

void Acceptor::bind()
{
    int ret = ::bind(_listenFd.fdGet(), (struct sockaddr*)_inetAddr.sockaddrInPtrGet(), sizeof(struct sockaddr_in));
    if (-1 == ret) { ERROR_EXIT("bind"); }
}

void Acceptor::listen()
{
    int ret = ::listen(_listenFd.fdGet(), LISTEN_SZ);
    if (-1 == ret) { ERROR_EXIT("listen"); }
}

int Acceptor::accept(InetAddress& cliInetAddr)
{   socklen_t len = sizeof(struct sockaddr_in);
    int acceptFd = ::accept(_listenFd.fdGet(), (struct sockaddr*)cliInetAddr.sockaddrInPtrGet(), &len);
    if (-1 == acceptFd) { ERROR_EXIT("accept"); }
    return acceptFd;
}

}
