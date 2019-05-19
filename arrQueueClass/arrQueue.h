#ifndef __ARR_QUEUE_H__ 
#define __ARR_QUEUE_H__
#define QUE_CAP 10

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

class Queue
{
public:
    Queue();
    ~Queue();
    void push(int iVal);
    void pop();
    int front() const;
    int back() const;
    bool empty() const;
    bool full() const;
private:
    int * _pArrayQue;
    int _size;
    int _rear;
    int _front;
};

#endif

