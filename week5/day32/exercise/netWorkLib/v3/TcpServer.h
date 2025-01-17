#pragma once
#include "noncopyable.h"
#include "acceptor.h"
#include "eventLoop.h"

namespace wd
{

class TcpServer
: Noncopyable
{
public:
    TcpServer(const string ip, const unsigned short port);
    void start();

    void setTcpOnConnectCallBack(CallBackFunc&&);
    void setTcpOnMessageCallBack(CallBackFunc&&);
    void setTcpOnCloseCallBack(CallBackFunc&&);
private:
    Acceptor _acceptor;
    EventLoop _eventLoop;
};

}
