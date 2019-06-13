#pragma once
#include "noncopyable.h"
#include "inetAddress.h"
#include "socket.h"

namespace wd
{

class Acceptor
: protected Noncopyable
{
public:
    Acceptor(const string&, const unsigned short&);
    int socket();
    void setReuseAddr();
    void setReusePort();
    void bind();
    void listen();
    int accept(InetAddress&);
    int listenFdGet() const { return _listenFd.fdGet(); }
private:
    InetAddress _inetAddr;
    Socket _listenFd;
};

}
