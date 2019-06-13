#pragma once
#include "inetAddress.h"
#include "socket.h"
#include "socketIO.h"

namespace wd
{

class TcpConnection
{
public:
    TcpConnection(int);
    string recv();
    void send(const string&);
    string toString();
    ~TcpConnection();
private:
    InetAddress getLocalInetAddr(int);
    InetAddress getPeerInetAddr(int);
private:
    Socket _acceptFd;
    SocketIO _sockIO;
    InetAddress _localInetAddr;
    InetAddress _peerInetAddr;
    bool _isShutdownWrite;
};

}
