#pragma once
#include "mutexClock.h"
#include "condition.h"

#include <vector>
#include <queue>

using namespace std;

namespace wd
{

class TaskQueue
{
public:
    TaskQueue(size_t qs)
        : _queueSize(qs), _queue(),
        _mutex(), _notEmpty(_mutex),
        _notFull(_mutex) {}
    bool empty() const;
    bool full() const;
    void push(int);
    int pop();
private:
    size_t _queueSize;
    queue<int> _queue;
    MutexLock _mutex;
    Condition _notEmpty;
    Condition _notFull;
};

}
