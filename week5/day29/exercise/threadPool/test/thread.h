#ifndef __THREAD_H__
#define __THREAD_H__
#include "noncopyable.h"

#include <pthread.h>

#include <iostream>
#include <functional>

using namespace std;

namespace wd
{

class Thread
: protected Noncopyable
{
    using CallBackFunc_t = function<void()>;
public:
    Thread(CallBackFunc_t&& cb) : _cb(cb), _isRunning(false) { cout << "Thread()" << endl; }
    void start();
    void join();
    ~Thread();
private:
    static void* threadFunc(void* args);
private:
    pthread_t _thId;
    CallBackFunc_t _cb;
    bool _isRunning;
};

}

#endif

