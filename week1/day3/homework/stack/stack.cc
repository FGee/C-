#include "stack.h"

Stack::Stack()
{
    cout << "Stack:()" << endl;
    _stackArr = new int[10];
    _stackPoint = -1;
}

Stack::~Stack()
{
    cout << "~Stack()" << endl;
    delete [] _stackArr;
}

void Stack::push(int ival)
{
    if (_stackPoint < 9) {
        _stackArr[++_stackPoint] = ival;
    } else {
        cout << "stack overflow_error" << endl;
    }
}

void Stack::pop()
{
    if (_stackPoint > -1) {
        --_stackPoint;
    } else {
        cout << "stack is empty" << endl;
    }
}

int Stack::top() const
{
    return _stackArr[_stackPoint];
}

bool Stack::empty() const
{
    if (-1 == _stackPoint) {
        return false;
    } else {
        return true;
    }
}

bool Stack::full() const
{
    if (9 == _stackPoint) {
        return true;
    } else {
        return false;
    }
}
