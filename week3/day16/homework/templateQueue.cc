#include <iostream>

using std::cout;
using std::endl;

template <class T, int capacity = 5>
class CircleQueue
{
public:
    CircleQueue() 
        : _size(0), _arr(new T[capacity]()), _front(0), _rear(0)
    {
        cout << "CircleQueue()" << endl;
    }
    ~CircleQueue()
    {
        delete [] _arr;
        cout << "~CircleQueue()" << endl;
    }
    bool isEmpty();
    bool isFull();
    void push(T& rt);
    void pop();
    T front();
    T back();
private:
    T* _arr;
    int _size;
    int _front;
    int _rear;
};

template <class T, int capacity>
bool CircleQueue<T, capacity>::isEmpty()
{
    if (_front == _rear) {
        return true;
    } else {
        return false;
    }
}

template <class T, int capacity>
bool CircleQueue<T, capacity>::isFull()
{
    if ((_rear + 1) % capacity == _front) {
        return true;
    } else {
        return false;
    }
}

template <class T, int capacity>
void CircleQueue<T, capacity>::push(T& rt)
{
    if (isFull()) {
        cout << "the circle queue is full" << endl;
    } else {
        _arr[_rear] = rt;
        ++_rear;
        _rear %= capacity;
    }
}

template <class T, int capacity>
void CircleQueue<T, capacity>::pop()
{
    if (isEmpty()) {
        cout << "the circle queue is empty" << endl;
    } else {
        ++_front;
        _front %= capacity;
    }
}

template <class T, int capacity>
T CircleQueue<T, capacity>::front()
{
    if (isEmpty()) {
        cout << "the circle queue is empty" << endl;
    } else {
        return _arr[_front];
    }
}

template <class T, int capacity>
T CircleQueue<T, capacity>::back()
{
    if (isEmpty()) {
        cout << "the circle queue is empty" << endl;
    } else {
        return _arr[(_rear - 1 + capacity) % capacity];
    }
}

int main()
{
    CircleQueue<int> cir;
    cout << "if empty: " << cir.isEmpty() << endl;

    for (int i = 0; i < 6; ++i) {
        cir.push(i);
    }

    cout << "if full: " << cir.isFull() << endl;
    
    cout << "front: " << cir.front() << endl;

    cout << "back: " << cir.back() << endl;

    cir.pop();

    cout << "front: " << cir.front() << endl; 


    return 0;
}
