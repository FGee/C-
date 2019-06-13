#include "thread.h"

namespace wd
{

void Thread::start()
{
    if (!_isRunning) {
        int ret = pthread_create(&_thId, nullptr, threadFunc, this);
        if (!ret) {
            perror("pthread_create");
        }
        _isRunning = true;
    }
}

void Thread::join()
{
    if (_isRunning) {
        pthread_join(_thId, nullptr);
    }
}

void* Thread::threadFunc(void* args)
{
    Thread* pThread = static_cast<Thread*>(args);
    if (pThread) {
        pThread->_cb();
    }
    return nullptr;
}

Thread::~Thread()
{
    if (_isRunning) {
        pthread_detach(_thId);
    } 
    cout << "~Thread()" << endl;
}

}
