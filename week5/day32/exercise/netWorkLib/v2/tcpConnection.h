#pragma once
#include "noncopyable.h"
#include "inetAddress.h"
#include "socket.h"
#include "socketIO.h"

#include <functional>
#include <memory>

using namespace std;

namespace wd
{

class TcpConnection;

using CallBackFunc = function<void(const shared_ptr<TcpConnection>)>;

class TcpConnection
: Noncopyable
, public enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(int);
    string recv();
    void send(const string&);
    string toString();
    ~TcpConnection();

    void setOnConnectCallBack(CallBackFunc);
    void setOnMessageCallBack(CallBackFunc);
    void setOnCloseCallBack(CallBackFunc);

    void doOnConnectCallBack();
    void doOnMessageCallBack();
    void doOnCloseCallBack();
private:
    InetAddress getLocalInetAddr(int);
    InetAddress getPeerInetAddr(int);
private:
    Socket _acceptFd;
    SocketIO _sockIO;
    InetAddress _localInetAddr;
    InetAddress _peerInetAddr;
    bool _isShutdownWrite;

    CallBackFunc _onConnect;
    CallBackFunc _onMessage;
    CallBackFunc _onClose;
};

}
