#include "mutex_cond.h"

int main()
{
    MutexLock mutexLock;

    Condition condition(&mutexLock);

    condition.wait();
    
    condition.notify();

    condition.notifyall();

    return 0;
}
