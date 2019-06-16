#include "TcpServer.h"

namespace wd
{

TcpServer::TcpServer(const string ip, const unsigned short port)
    : _acceptor(ip, port), _eventLoop(_acceptor) {}

void TcpServer::start()
{
    _acceptor.ready();
    _eventLoop.loop();
}

void TcpServer::setTcpOnConnectCallBack(CallBackFunc&& cb)
{
    _eventLoop.setOnConnect(move(cb));
}

void TcpServer::setTcpOnMessageCallBack(CallBackFunc&& cb)
{
    _eventLoop.setOnMessage(move(cb));
}

void TcpServer::setTcpOnCloseCallBack(CallBackFunc&& cb)
{
    _eventLoop.setOnClose(move(cb));
}

}
