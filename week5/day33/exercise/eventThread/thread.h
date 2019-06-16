#ifndef __THREAD_H__
#define __THREAD_H__
#include "noncopyable.h"

#include <pthread.h>

#include <iostream>
#include <functional>

using namespace std;

extern __thread const char* threadName;

namespace wd
{
    using CallBackFunc_t = function<void()>;

class Thread
: protected Noncopyable
{
public:
    Thread(CallBackFunc_t&& cb, const string& name = string()) 
        : _cb(move(cb)), _isRunning(false), 
        _name(name) 
    { cout << "Thread()" << endl; }
    void start();
    void join();
    ~Thread();
private:
    static void* threadFunc(void* args);
private:
    pthread_t _thId;
    CallBackFunc_t _cb;
    bool _isRunning;
    string _name;
};

}

#endif

