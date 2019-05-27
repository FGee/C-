#include "MutexClock.h"
#include "Condition.h"

#include <unistd.h>

#include <iostream>

typedef struct {
    wd::MutexLock mutex;
    wd::Condition cond;
} MutexCond_t, *pMutexCond_t;

bool flag = false;

int gTicket = 100;

wd::MutexLock mutex;
wd::Condition cond(mutex);

void* threadHandle1(void* Args)
{
    int cnt = 10;
    while (cnt) {
        {
            wd::MutexLockGuard autoLock(mutex);
            if (flag) {
                cond.wait();
            }
            cout << "th1: " << pthread_self() << " the ticket remain: " << gTicket << endl;
            --gTicket;
            if (!flag) {
                flag = true;
            }
        }
        cond.notify();
        --cnt;
        cout << "th1: " << pthread_self() << " the ticket remain: " << gTicket << endl;
        sleep(1);
    }

    return nullptr;
}

void* threadHandle2(void* Args)
{
    int cnt = 10;
    while (cnt) {
        {
            wd::MutexLockGuard autoLock(mutex);
            if (!flag) {
                cond.wait();
            }
            cout << "th2: " << pthread_self() << " the ticket remain: " << gTicket << endl;
            --gTicket;
            if (flag) {
                flag = false;
            }
            return nullptr;//test for autoLock
        }
        cond.notify();
        --cnt;
        cout << "th2: " << pthread_self() << " the ticket remain: " << gTicket << endl;
        sleep(1);
    }

    return nullptr;
}

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, threadHandle1, NULL);
    pthread_create(&th2, NULL, threadHandle2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}
