#ifndef __MUTEX_COND_H__
#define __MUTEX_COND_H__
#include <pthread.h>
#include <unistd.h>

#include <iostream>

using std::cout;
using std::endl;

class MutexLock
{
public:
    void lock();
    void unlock();
    MutexLock();
    ~MutexLock();
    pthread_mutex_t* _pLock;
private:
    //pthread_mutex_t* _pLock;
};

class Condition
{
public:
    Condition(MutexLock*);
    ~Condition();
    void wait();
    void notify();
    void notifyall();
private:
    pthread_cond_t* _pCond;
    MutexLock* _pMutexLock;
};
#endif
