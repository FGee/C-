#include "threadPool.h"
#include "workThread.h"
#include "myTask.h"

#include <unistd.h>

namespace wd
{

void ThreadPool::start()
{
    for (size_t i = 0; i < _threadNum; ++i) {
        unique_ptr<Thread> newThread(new WorkThread(*this));
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
        for (auto & thread : _threads) {
            thread->join();
        }

    }
}

void ThreadPool::addTask(Task* task)
{
    _taskQue.push(task);
}

Task* ThreadPool::getTask()
{
    return _taskQue.pop();
}

void ThreadPool::threadFunc()
{
    while (!_isExit) {
        Task* task = getTask();
        if (task) {
            task->process();
        }
    }
}

}
