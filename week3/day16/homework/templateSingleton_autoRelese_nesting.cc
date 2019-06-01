#include <string.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Point
{
public:
    Point(int ix, int iy) : _ix(ix), _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }
    ~Point() { cout << "~Point()" << endl; }
    friend std::ostream& operator<<(std::ostream& os, Point& pt);
private:
    int _ix;
    int _iy;
};

std::ostream& operator<<(std::ostream& os, Point& pt)
{
    os << "(" << pt._ix << ", " << pt._iy << endl;
    return os;
}

class Computer
{
public:
    Computer(const char* band, double price) 
        : _band(new char[strlen(band) + 1]()), _price(price)
    {
        strcpy(_band, band);
        cout << "Computer(const char*, double)" << endl;
    }
    ~Computer()
    {
        delete [] _band;
        cout << "~Computer()" << endl;
    }
    friend std::ostream& operator<<(std::ostream& os, Computer& com);
private:
    char* _band;
    double _price;
};
std::ostream& operator<<(std::ostream& os, Computer& com)
{
    os << "Band: " << com._band << endl;
    os << "Price: " << com._price << endl;
    return os;
}

template <class T>
class TemplateSingleton
{
public:
    class AutoRelease
    {
    public:
        AutoRelease() { cout << "AutoRelease()" << endl; }
        ~AutoRelease() {
            if (nullptr != _pT) {
                delete _pT;
                cout << "~AutoRelease()" << endl;
            }
        }
    };
public:
    template <typename...Args>
    static T* getInstance(Args...args)
    {
        if (nullptr == _pT) {
            _pT = new T(args...);
            (void)_auto;
        }
        return _pT;
    }
private:
    TemplateSingleton();
    ~TemplateSingleton() { cout << "~TemplateSingleton()" << endl; }
private:
    static T* _pT;
    static AutoRelease _auto;
};

template <class T>
T* TemplateSingleton<T>::_pT = nullptr;

template <class T>
typename TemplateSingleton<T>::AutoRelease TemplateSingleton<T>::_auto;

int main()
{
    Computer* p1 = TemplateSingleton<Computer>::getInstance("Xiaomi", 6666);
    cout << *p1 << endl;

    return 0;
}

