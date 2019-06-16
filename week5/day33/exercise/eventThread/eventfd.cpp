#include "eventfd.h"
#include "macro.h"

#include <sys/eventfd.h>
#include <poll.h>
#include <string.h>
#include <unistd.h>

#include <iostream>

using namespace std;

namespace wd
{

EventFd::EventFd(CallBackFunc_t&& cb) 
    : _evFd(create()), _cb(move(cb)), _isLooping(false) {}

int EventFd::create()
{
    //int evFd = eventfd(0, 0); // 如果为0的话，则第一次不会去执行
    int evFd = eventfd(6, 0);

    if (-1 == evFd) { ERROR_EXIT("eventfd"); }
    return evFd;
}

void EventFd::start()
{
    _isLooping = true;

    struct pollfd pllFd;
    memset(&pllFd, 0, sizeof(struct pollfd));
    pllFd.fd = _evFd;
    pllFd.events = POLLIN;

    while (_isLooping) {
        int readyNum = poll(&pllFd, 1, 5000);

        if (-1 == readyNum && errno == EINTR) {
            continue;
        } else if (-1 == readyNum) {
            ERROR_EXIT("poll");
        } else if (0 == readyNum) {
            cout << "****Time out****" << endl;
        } else {
            if (pllFd.fd == _evFd && pllFd.events & POLLIN) {
                handleRead();
                _cb();
            }
        }
    }
}

void EventFd::handleRead()
{
    uint64_t number;
    int ret = read(_evFd, &number, sizeof(number));

    if (sizeof(uint64_t) != ret) { ERROR_EXIT("read"); }
}

void EventFd::weak()
{
    uint64_t number = 666;
    int ret = write(_evFd, &number, sizeof(number));

    if (sizeof(uint64_t) != ret) { ERROR_EXIT("write"); }
}

void EventFd::stop()
{
    _isLooping = false;
}

}
