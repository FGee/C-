#include "eventLoop.h"
#include "macro.h"

namespace wd
{

EventLoop::EventLoop(Acceptor& a) 
    : _epFd(epollCreate()), _acceptor(a),
    _events(64), _isLooping(false) {}

int EventLoop::epollCreate()
{
    int tmp = epoll_create(1);
    if (-1 == tmp) { ERROR_EXIT("epoll_create"); }
    return tmp;
}

void EventLoop::loop()
{
    _isLooping = true;
    while (_isLooping) {
        epollWait();
    }
}

void EventLoop::epollWait()
{
    int readyNum = epoll_wait(_epFd, &*_events.begin(), _events.size(), 5000);
    for (int i = 0; i < readyNum; ++i) {
        if (_events[i].data.fd == _acceptor.listenFdGet()) {
            if (_events[i].data.fd & EPOLLIN) {
                handleConnect();
            }
        }
    }
}

void EventLoop::handleConnect()
{
    //SPtrConn tmpNew(new TcpConnection(_acceptor.accept(tmp)));
}

}
