#include <iostream>
#include <algorithm>
#include <memory>

using std::cout;
using std::endl;
using std::cin;
using std::allocator;

template <typename T>
class Vector
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T* iterator;
    typedef const T* const_iterator;

    Vector() : _size(0), _capacity(0),
    _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
    { cout << "Vector()" << endl; };
    ~Vector() { cout << "~Vector()" << endl; }
    void push_back(const T &);
    void pop_back();
    const_iterator begin() { return _start; };
    const_iterator end() { return _finish; };
    int size() { return _size; };
    int capacity() { return _capacity; };
    T& operator[](size_t index) const;
private:
    void reallocate();
private:
    int _size;
    int _capacity;
    T* _start;
    T* _finish;
    T* _end_of_storage;
    static std::allocator<T> _alloc;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & t)
{
    if (_size == _capacity) {
        reallocate();
    }
    *_finish++ = t;
    //_alloc.construct(_finish++, t);
    ++_size;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (_size) {
        _alloc.destroy(_finish--);
        --_size;
        return;
    }
}

template <typename T>
void Vector<T>::reallocate()
{
    size_t old_capa = _capacity;
    _capacity = ( 0 == _capacity ) ? 1 : _capacity * 2;
    T* ptTmp = _alloc.allocate(_capacity);
    std::copy(_start, _finish, ptTmp);
    //std::uninitialized_copy(_start, _finish, ptTmp);

    T* ptrStart = _start;
    while (_start != _finish) {
        _alloc.destroy(_start++);
    }
    _alloc.deallocate(ptrStart, old_capa);

    _start = ptTmp;
    _finish = ptTmp + old_capa;
    _end_of_storage = ptTmp + _capacity;
}

template <typename T>
T& Vector<T>::operator[](size_t index) const
{
    if (index >= 0 && index < _size) {
        return _start[index];
    }
}

template <typename Container>
void display(Container & container)
{
    typename Container::const_iterator begIter = container.begin();
    typename Container::const_iterator endIter = container.end();

    while (begIter != endIter) {
        cout << *begIter++ << " ";
    }
    cout << "\nsize: " << container.size() << endl
         << "capacity: " << container.capacity() << endl;

    typename Container::value_type val;
    val = 66666;
    cout << "value_type val = : " << val << endl;
}

int main()
{
    Vector<int> myvec;

    for (int i = 0; i < 10; ++i) {
        myvec.push_back(i);
        display(myvec);
    }
    cout << "myvec[1]: " << myvec[1] << endl;

    //for (int i = 0; i < 11; ++i) {
    //    myvec.pop_back();
    //    display(myvec);
    //}

    return 0;
}

