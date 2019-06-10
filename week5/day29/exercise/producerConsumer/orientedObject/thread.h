#ifndef __THREAD_H__
#define __THREAD_H__
#include "noncopyable.h"

#include <pthread.h>
#include <stdio.h>
#include <errno.h>

#include <iostream>

using namespace std;

namespace wd
{

class Thread
: protected Noncopyable
{
public:
    Thread() : Noncopyable(), _isRunning(false) {}
    void start();
    void join();
    virtual ~Thread(); 
private:
    virtual
        void run() = 0;
    static void* threadHandleFunc(void* Args);
private:
    pthread_t _thId;
    bool _isRunning;
};

}

#endif

