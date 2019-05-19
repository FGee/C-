#include "arrQueue.h"

Queue::Queue() : _pArrayQue(new int[QUE_CAP]()), _size(0), _rear(0), _front(0) 
{
    cout << "Queue()" << endl;
}

Queue::~Queue()
{
    delete [] _pArrayQue;
    cout << "~Queue()" << endl;
}

bool Queue::empty() const
{
    if (_rear == _front)
    {
        return true;
    } else {
        return false;
    }
}

bool Queue::full() const
{
    if (_front == (_rear + 1) % QUE_CAP) {
        return true;
    } else {
        return false;
    }
}

void Queue::push(int iVal) 
{
    if (!full()) {
        _pArrayQue[_rear] = iVal;
        ++_rear;
        _rear = _rear % QUE_CAP;
    } else {
        cout << "the queue is full" << endl;
    }
}

void Queue::pop()
{
    if (!empty()) {
        ++_front;
        _front = _front % QUE_CAP;
    } else {
        cout << "the queue is empty" << endl;
    }
}

int Queue::front() const
{
    if (!empty()) {
        return _pArrayQue[_front];
    }
    return -1;
}

int Queue::back() const
{
    if (!empty()) {
        return _pArrayQue[(_rear - 1 + QUE_CAP) % QUE_CAP];
    }
    return -1;
}
