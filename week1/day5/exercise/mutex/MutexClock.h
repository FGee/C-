#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__
#include <stdio.h>
#include <error.h>
#include <pthread.h>

#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

class MutexLock
{
public:
    MutexLock() : _isLocking(false)
    {
        if (pthread_mutex_init(&_mutex, NULL)) {
            perror("pthread_mutex_init");
        }
    }
    ~MutexLock()
    {
        if (pthread_mutex_destroy(&_mutex)) {
            perror("pthread_mutex_destroy");
        }
    }
    void lock()
    {
        if (pthread_mutex_lock(&_mutex)) {
            perror("pthread_mutex_lock");
        }
        _isLocking = true;
    }
    void unlock()
    {
        if (pthread_mutex_unlock(&_mutex)) {
            perror("pthread_mutex_unlock");
        }
        _isLocking = false;
    }
    bool isLocking() const { return _isLocking; }
    pthread_mutex_t * getMutexLockPtr() { return &_mutex; }
#if 0
private:
    MutexLock(const MutexLock &);
    MutexLock & operator=(const MutexLock);
#endif
private:
    pthread_mutex_t _mutex;
    bool _isLocking;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex) : _mutex(mutex) 
    {
        _mutex.lock();
    }
    ~MutexLockGuard() 
    {
        _mutex.unlock();
    }
private:
    MutexLock& _mutex;
};

}

#endif

