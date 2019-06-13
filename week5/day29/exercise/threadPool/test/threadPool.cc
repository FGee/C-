#include "threadPool.h"
#include "thread.h"
#include "myTask.h"

#include <unistd.h>

namespace wd
{

void ThreadPool::start()
{
    for (size_t i = 0; i < _threadNum; ++i) {
        unique_ptr<Thread> newThread(
        new Thread(bind(&ThreadPool::threadFunc, this)));
        _threads.push_back(move(newThread));
    }
    for (auto & thread : _threads) {
        thread->start(); 
    }
}

void ThreadPool::stop()
{
    if (!_isExit) {
        while (!_taskQue.empty()) {
            sleep(1);
        } 
        _isExit = true;
        _taskQue.weak();
        for (auto & thread : _threads) {
            thread->join();
        }

    }
}

void ThreadPool::addTask(CallBackFunc&& task) //无论是否为右值引用，均可以运行，只是表达的不是移动语义罢了
{
    _taskQue.push(task);
}

CallBackFunc ThreadPool::getTask()
{
    return _taskQue.pop();
}

void ThreadPool::threadFunc()
{
    while (!_isExit) {
        CallBackFunc task = getTask();
        if (task) {
            task();
        }
    }
}

}
