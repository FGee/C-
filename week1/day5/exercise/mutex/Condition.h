#ifndef __CONDITON_H__
#define __CONDITON_H__
#include "MutexClock.h"

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

namespace wd
{
class Condition
{
public:
    Condition(MutexLock & mutex)
        : _mutex(mutex)
    {
        if (pthread_cond_init(&_cond, nullptr)) {
            perror("pthread_cond_init");
        }
    }

    Condition(const Condition & rhs) = delete;
    Condition & operator=(const Condition & rhs) = delete;

    void wait()
    {
        if (pthread_cond_wait(&_cond, _mutex.getMutexLockPtr())) {
            perror("pthread_cond_wait");
        }
    }

    void notify()
    {
        if (pthread_cond_signal(&_cond)) {
            perror("pthread_cond_signal");
        }
    }

    void notifyAll()
    {
        if (pthread_cond_broadcast(&_cond)) {
            perror("pthread_cond_broadcast");
        }
    }

    ~Condition()
    {
        if (pthread_cond_destroy(&_cond)) {
            perror("pthread_cond_destroy");
        }
    }
private:
    pthread_cond_t _cond;
    MutexLock& _mutex;
};
}
#endif
