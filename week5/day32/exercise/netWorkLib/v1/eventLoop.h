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
private:
    int epollCreate();
    void epollWait();
    void handleConnect();
    void handMessage();
    void addEvent();
    void deleteEvent();
private:
    int _epFd;
    Acceptor& _acceptor;
    map<int, SPtrConn> _conns;
    vector<struct epoll_event> _events;
    bool _isLooping;
};

}
