#include "thread.h"

namespace wd
{

void Thread::start()
{
    if (!_isRunning) {
        _thId = pthread_create(&_thId, nullptr, threadHandleFunc, this);
        if (_thId) {
            perror("pthread_create");
            return;
        }
        _isRunning = true;
    }
}

void Thread::join()
{
    if (_isRunning) {
        pthread_join(_thId, NULL);
    }
}

void* Thread::threadHandleFunc(void* Args)
{
    Thread* pThread = static_cast<Thread*>(Args);
    if (pThread) {
        pThread->run();
    }
    return nullptr;
}

Thread::~Thread() 
{
    cout << "~Thread()" << endl;
    if (_isRunning) {
        pthread_detach(_thId);
    }
}

}
