#include "memberFuncAddress.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class A
{
public:
    virtual 
        void a()
        {
            cout << "A::a()" << endl;
        }
    void b()
    {
        cout << "A::b()" << endl;
    }
    void c()
    {
        cout << "A::c()" << endl;
    }
private:
};

class B
: public A
{
public:
    void a()
    {
        cout << "B::a()" << endl;
    }
    void b()
    {
        cout << "B::b()" << endl;
    }
    void c()
    {
        cout << "B::c()" << endl;
    }
    void d()
    {
        cout << "B::d()" << endl;
    }
private:
};

void print()
{
    cout << "hi" << endl;
}

int main()
{
    A* pa = (A*)new B;
    B* pb = dynamic_cast<B*>(pa);
    if (nullptr == pb) {
        cout << "transform error" << endl;
    } else {
        pb->d();
    }

    cout << "---------------test 2-------------" << endl;
    A* pa1 = new A;
    B* pb2 = dynamic_cast<B*>(pa1);
    if (nullptr == pb2) {
        cout << "transform error" << endl;
    } else {
        pb2->d();
    }

    return 0;
}

