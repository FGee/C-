#pragma once
#include "mutexClock.h"
#include "condition.h"

#include <vector>
#include <queue>

using namespace std;

namespace wd
{

class Task;
using ElemType = Task*;

class TaskQueue
{
public:
    TaskQueue(size_t qs)
        : _queueSize(qs), _queue(),
        _mutex(), _notEmpty(_mutex),
        _notFull(_mutex) {}
    bool empty() const;
    bool full() const;
    void push(const ElemType&);
    ElemType pop();
private:
    size_t _queueSize;
    queue<ElemType> _queue;
    MutexLock _mutex;
    Condition _notEmpty;
    Condition _notFull;
};

}
