#include "eventThread.h"

namespace wd
{

EventThread::EventThread(CallBackFunc_t&& cb, const string& name)
    : _event(move(cb)), 
    _thread(bind(&EventFd::start, &_event), name) {}

void EventThread::start() 
{
    _thread.start();
}

void EventThread::weak()
{
    _event.weak();
}

void EventThread::stop()
{
    _event.stop();
    _thread.join();
}

}
