#pragma once
#include "tcpConnection.h"
#include "acceptor.h"

#include <sys/epoll.h>

#include <map>
#include <vector>
#include <memory>

using namespace std;

namespace wd
{
    using SPtrConn = shared_ptr<TcpConnection>;
class EventLoop
{
public:
    EventLoop(Acceptor&);
    void loop();
    void unloop();

    void setOnConnect(CallBackFunc&&);
    void setOnMessage(CallBackFunc&&);
    void setOnClose(CallBackFunc&&);
private:
    int epollCreate();
    void epollWait();
    
    void handleNewConnect();
    void addEventRead(int);
   
    void handleMessage(int);
    bool isConnectionClosed(int);
    
    void handleConnectClose(int);
    void deleteEventRead(int);
private:
    int _epFd;
    Acceptor& _acceptor;
    map<int, SPtrConn> _conns;
    vector<struct epoll_event> _events;
    bool _isLooping;
    
    CallBackFunc _onConnect;
    CallBackFunc _onMessage;
    CallBackFunc _onClose;
};

}
