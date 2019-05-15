#include "queue.h"

Queue::Queue()
    : _queueHead(nullptr), _queueTail(nullptr), _queueSize(0), _queueCapacity(5)
{
    cout << "Queue()" << endl;
}

Queue::~Queue()
{
    pNode_t pdel, pcur;
    pdel = pcur = _queueHead;
    while (nullptr != pcur) {
        pdel = pcur;
        pcur = pcur->pNext;
        delete pdel;
    }
    cout << "~Queue()" << endl;
}

void Queue::push(int ival)
{
    cout << "push()" << endl;
    if (_queueSize < _queueCapacity) {
        pNode_t pnew = new Node_t;
        pnew->key = ival;
        pnew->pPre = nullptr;
        pnew->pNext = nullptr;
        if (nullptr == _queueHead) {
            _queueHead = _queueTail = pnew;
        } else {
            pnew->pPre = nullptr;
            pnew->pNext = _queueHead;
            _queueHead->pPre = pnew;
            _queueHead = pnew;
        }
        ++_queueSize;
    } else {
        cout << "the queue is full" << endl;
    }
}

void Queue::pop()
{
    cout << "pop()" << endl;
    pNode_t pdel;
    if (nullptr == _queueTail) {
        cout << "the queue is empty" << endl;
    } else if (_queueHead == _queueTail) {
        delete _queueTail;
        _queueHead = _queueTail = nullptr;
        --_queueSize;
    } else {
        pdel = _queueTail;
        _queueTail->pPre->pNext = nullptr;
        _queueTail = _queueTail->pPre;
        delete pdel;
        --_queueSize;
    }
}

int Queue::front() const
{
    if (nullptr == _queueTail) {
        cout << "the queue is empty" << endl;
        return -1;
    } else {
        return _queueTail->key;
    }
}

int Queue::back() const 
{
    if (nullptr == _queueHead) {
        cout << "the queue is empty" << endl;
        return -1;
    } else {
        return _queueHead->key;
    }
}

bool Queue::empty() const
{
    if (0 == _queueSize) {
        return true;
    } else {
        return false;
    }
}

bool Queue::full() const
{
    if (_queueSize == _queueCapacity) {
        return true;
    } else {
        return false;
    }
}
