#pragma once
#include "noncopyable.h"

#include <functional>

using namespace std;

namespace wd
{

class EventFd
: Noncopyable
{
    using CallBackFunc_t = function<void()>;
public:
    EventFd(CallBackFunc_t&&);
    void start();
    void stop();
    void weak();
private:
    int create();
    void handleRead();
private:
    int _evFd;
    CallBackFunc_t _cb;
    bool _isLooping;
};

}
