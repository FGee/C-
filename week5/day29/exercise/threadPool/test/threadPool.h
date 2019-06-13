#pragma once
#include "taskQueue.h"
#include "thread.h"
#include "myTask.h"
#include "thread.h"

#include <vector>
#include <memory>
#include <functional>

using namespace std;

namespace wd
{
using CallBackFunc = function<void()>;
class ThreadPool
{
    friend class Thread;
public:
    ThreadPool(size_t qs, size_t ts)
        : _taskQue(qs), _queSize(qs),
        _threadNum(ts), _isExit(false) 
    { _threads.reserve(_threadNum); }
    void start();
    void stop();
    void addTask(CallBackFunc&&);
private:
    CallBackFunc getTask();
    void threadFunc();
private:
    TaskQueue _taskQue;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;
    size_t _threadNum;
    bool _isExit;
};

}
