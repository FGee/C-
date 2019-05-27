#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using std::cout;
using std::endl;

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int);
    void pop();
    int top() const;
    bool empty() const;
    bool full() const;
private:
    int* _stackArr;
    int _stackPoint;
};

#endif
