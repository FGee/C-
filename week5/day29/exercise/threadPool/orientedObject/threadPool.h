#pragma once
#include "taskQueue.h"
#include "thread.h"
#include "myTask.h"

#include <vector>
#include <memory>

using namespace std;

namespace wd
{

class ThreadPool
{
    friend class WorkThread;
public:
    ThreadPool(size_t qs, size_t ts)
        : _taskQue(qs), _queSize(qs),
        _threadNum(ts), _isExit(false) 
    { _threads.reserve(_threadNum); }
    void start();
    void stop();
    void addTask(Task*);
private:
    Task* getTask();
    void threadFunc();
private:
    TaskQueue _taskQue;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;
    size_t _threadNum;
    bool _isExit;
};

}
