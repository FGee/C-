#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <class T, int sz>
class Stack
{
public:
    Stack() {
        _point = 0;
    }
    ~Stack() { cout << "~Stack()" << endl; }
    bool isEmpty()
    {
        return 0 == _point;
    }
    bool isFull();
    void push(T& rhs);
    void pop(T& rhs);
private:
    int _point;
    T _classArr[sz];
};

template <class T, int sz>
bool Stack<T, sz>::isFull()
{
    return sz == _point;
}

template <class T, int sz>
void Stack<T, sz>::push(T& rhs)
{
    if (isFull()) {
        cout << "the stack is full" << endl;
    } else {
        _classArr[_point] = rhs;
        ++_point;
    }
}

template <class T, int sz>
void Stack<T, sz>::pop(T& rhs)
{
    if (isEmpty()) {
        cout << "the stack is empty" << endl;
    } else {
        --_point;
        rhs = _classArr[_point];
    }
}

int main()
{
    Stack<int, 5> st;
    cout << "if empty: " << st.isEmpty() << endl;
    for (int i = 0; i < 6; ++i) {
        st.push(i);
    }
    cout << "if full: " << st.isFull() << endl;

    int a;
    st.pop(a);
    cout << "pop: a = " << a << endl;

    return 0;
}

