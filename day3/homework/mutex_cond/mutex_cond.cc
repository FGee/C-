#include "mutex_cond.h"

MutexLock::MutexLock()
{
    _pLock = new pthread_mutex_t;
    pthread_mutex_init(_pLock, NULL);
    cout << "MutexLock()" << endl;
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(_pLock);
    delete _pLock;
    cout << "~MutexLock()" << endl;
}

void MutexLock::lock()
{
    pthread_mutex_lock(_pLock);
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(_pLock);
}

Condition::Condition(MutexLock* pMutexLock) : _pMutexLock(pMutexLock)
{
    _pCond = new pthread_cond_t;
    pthread_cond_init(_pCond, NULL);
    cout << "Condition()" << endl;
}

Condition::~Condition()
{
    pthread_cond_destroy(_pCond);
    delete _pCond;
    cout << "~Condition()" << endl;
}

void Condition::wait()
{
    _pMutexLock->lock();
    pthread_cond_wait(_pCond, _pMutexLock->_pLock);
}

void Condition::notify()
{
    pthread_cond_signal(_pCond);
}

void Condition::notifyall()
{
    pthread_cond_broadcast(_pCond);
}
