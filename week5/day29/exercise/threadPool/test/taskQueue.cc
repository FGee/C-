#include "taskQueue.h"

namespace wd
{

inline
    bool TaskQueue::empty() const { return 0 == _queue.size(); }

inline
    bool TaskQueue::full() const { return _queue.size() == _queueSize; }

void TaskQueue::push(const ElemType& elem) 
{
    {
        //MutexLockGuard autoMutex(_mutex);
        while (full()) {
            _notFull.wait();
        }
        _queue.push(elem);
    }
    _notEmpty.notify();
}

ElemType TaskQueue::pop()
{
    ElemType retElem;

    //MutexLockGuard autoMutex(_mutex);
    while (!_exitFlag && empty()) {
        cout << "11111111111" << endl;
        _notEmpty.wait();
        cout << "22222222222" << endl;
    }

    if (!_exitFlag) {
        retElem = _queue.front();
        _queue.pop();
        _notFull.notify();
        return retElem;
    } else {
        return nullptr;
        //return ElemType(); // 执行默认初始化的函数对象，执行后是一个nullptr
    }
}

void TaskQueue::weak()
{
    _exitFlag = true; 
    _notEmpty.notifyAll();
}

}
