#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using std::cout;
using std::endl;

typedef struct node {
    int key;
    struct node *pPre;
    struct node *pNext;
} Node_t, *pNode_t;

class Queue 
{
public:
    Queue();
    ~Queue();
    void push(int);
    void pop();
    int front() const;
    int back() const;
    bool empty() const;
    bool full() const;
private:
    pNode_t _queueHead;
    pNode_t _queueTail;
    int _queueSize;
    int _queueCapacity;
};

#endif
