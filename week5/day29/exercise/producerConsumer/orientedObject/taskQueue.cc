#include "taskQueue.h"

namespace wd
{

inline
bool TaskQueue::empty() const { return 0 == _queueSize; }

inline
bool TaskQueue::full() const { return _queue.size() == _queueSize; }

void TaskQueue::push(int ival) 
{
    {
        MutexLockGuard autoMutex(_mutex);
        while (full()) {
            _notFull.wait();
        }
        _queue.push(ival);
    }
    _notEmpty.notify();
}

int TaskQueue::pop()
{
    int retVal = 0;
    {
        MutexLockGuard autoMutex(_mutex);
        while (empty()) {
            _notEmpty.wait();
        }
        retVal = _queue.front();
        _queue.pop();
    }
    _notFull.notify();

    return retVal;
}

}
