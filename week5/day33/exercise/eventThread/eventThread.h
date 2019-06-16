#pragma once
#include "noncopyable.h"
#include "eventfd.h"
#include "thread.h"

#include <string>

using namespace std;

namespace wd
{

class EventThread
: Noncopyable
{
public:
    EventThread(CallBackFunc_t&&, const string&);
    void start();
    void weak();
    void stop();
private:
    EventFd _event;
    Thread _thread;
};

}
