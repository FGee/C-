//#ifndef 
//#define
#pragma once
template <class T, int num>
class Stack
{
public:
    int returnNum();
private:
    T sz[num];
};

template <class T1, int num1>
int Stack<T1, num1>::returnNum()
{
    return num1;
}
//#endif

