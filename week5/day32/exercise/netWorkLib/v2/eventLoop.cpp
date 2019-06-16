#include "eventLoop.h"
#include "macro.h"

#include <string.h>
#include <assert.h>

#include <iostream>

using namespace std;

namespace wd
{

EventLoop::EventLoop(Acceptor& a) 
    : _epFd(epollCreate()), _acceptor(a),
    _events(1024), _isLooping(false) {}

int EventLoop::epollCreate()
{
    int tmp = epoll_create(1);
    if (-1 == tmp) { ERROR_EXIT("epoll_create"); }
    return tmp;
}

void EventLoop::loop()
{
    _isLooping = true;

    addEventRead(_acceptor.listenFdGet()); // 先注册连接接收器的listenFd

    while (_isLooping) {
        epollWait();
    }
}

void EventLoop::unloop()
{
    if (_isLooping) {
        _isLooping = false;
    }
}

void EventLoop::epollWait()
{
    int readyNum;
    do {
        readyNum = epoll_wait(_epFd, &*_events.begin(), _events.size(), 5000);
    } while (readyNum == -1 && errno == EINTR);
    if (-1 == readyNum) {
        ERROR_EXIT("epoll_wait");
    } else {
        if (readyNum == static_cast<int>(_events.size())) { _events.resize(readyNum * 2); }
        for (int i = 0; i < readyNum; ++i) {
            int fd = _events[i].data.fd;
            
            if (fd == _acceptor.listenFdGet()) {
                if (_events[i].events & EPOLLIN) {
                    handleNewConnect();
                }
            } else {
                if (_events[i].events & EPOLLIN) {
                    handleMessage(fd);
                }
            }
        }
    }
}

void EventLoop::handleNewConnect()
{
    int newfd = _acceptor.accept();
    auto newConn = make_pair(newfd, make_shared<TcpConnection>(newfd));
    _conns.insert(newConn);
    addEventRead(newfd);
    
    auto spNewConn = _conns[newfd];

    spNewConn->setOnConnectCallBack(_onConnect);
    spNewConn->setOnMessageCallBack(_onMessage);
    spNewConn->setOnCloseCallBack(_onClose);

    _conns[newfd]->doOnConnectCallBack();
}

void EventLoop::addEventRead(int newfd)
{
    struct epoll_event tmp;
    memset(&tmp, 0, sizeof(struct epoll_event));
    tmp.events = EPOLLIN;
    tmp.data.fd = newfd;

    int ret = epoll_ctl(_epFd, EPOLL_CTL_ADD, newfd, &tmp);
    if (ret == -1) { ERROR_EXIT("epoll_ctl"); }
}

void EventLoop::handleMessage(int fd)
{
    bool closed = isConnectionClosed(fd);
    auto retIter = _conns.find(fd);
    assert(_conns.end() != retIter);
    
    if (true == closed) {
        handleConnectClose(fd);
    } else {
        auto spConn = _conns[fd];
        spConn->doOnMessageCallBack();
    }
}

bool EventLoop::isConnectionClosed(int fd)
{
    int ret;
    do {
        char buf[1024];
        ret = recv(fd, buf, sizeof(buf), MSG_PEEK);
    } while (-1 == ret && errno == EINTR);
    return 0 == ret;
}

void EventLoop::handleConnectClose(int fdClosed)
{
    _conns[fdClosed]->doOnCloseCallBack();
// 这里一定要注意取消epoll和删除conn的先后顺序，删除其conn的时候，会调用Socket对象中的析构函数
// 里的close（fdClosed）方法；在这之后进行epoll_ctl(EPOLL_CTL_DEL) 会返回-1并将errno置位
    //cout << ">> fd : " << fdClosed << endl;
    deleteEventRead(fdClosed); // 取消对fdClosed的监控

    auto retIter = _conns.find(fdClosed);
    _conns.erase(retIter); // 从map中删除这个TcpConnection的对象
}

void EventLoop::deleteEventRead(int fd)
{
    struct epoll_event tmp;
    memset(&tmp, 0, sizeof(struct epoll_event));
    tmp.data.fd = fd;

    int ret = epoll_ctl(_epFd, EPOLL_CTL_DEL, fd, &tmp);
    if (ret == -1) { ERROR_EXIT("epoll_ctl"); }
}

void EventLoop::setOnConnect(CallBackFunc&& cb) 
{ _onConnect = move(cb); }

void EventLoop::setOnMessage(CallBackFunc&& cb)
{ _onMessage = move(cb); }

void EventLoop::setOnClose(CallBackFunc&& cb)
{ _onClose = move(cb); }

}
