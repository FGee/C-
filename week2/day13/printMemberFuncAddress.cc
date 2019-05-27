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
    virtual
        void b()
        {
            cout << "A::b()" << endl;
        }
    virtual
        void c()
        {
            cout << "A::c()" << endl;
        }
private:
};

class B
{
public:
    virtual
        void a()
        {
            cout << "B::a()" << endl;
        }
    //virtual
        void b()
        {
            cout << "B::b()" << endl;
        }
        virtual
    void c()
    {
        cout << "B::c()" << endl;
    }
//private:
    //virtual
    void d()
    {
        cout << "B::d()" << endl;
    }
    float _fval = 6;
private:
};

void print()
{
    cout << "hi" << endl;
}

int main()
{
    cout << "----------------RTTI--------------" << endl;
    //A* pa1 = new A;
    //B* pb1 = (B*)pa1;
    double val = 22.22;
    B* pb1 = (B*)&val;
    pb1->d();
    typedef void (B::*pFunc)();
    pFunc pf = &B::d;
    (pb1->*pf)();
    void* p1 = pointer_cast<void*>(&B::d);
    void* p2 = union_cast<void*>(&B::d);
    //printf("adress d() = %p\n", *(pb1->*pf));
    cout << "adress: " << p1 << endl;
    cout << "adress: " << p2 << endl;

    printf("address fval = %p\n", &pb1->_fval);
    cout << "fval = " << pb1->_fval << endl;

    return 0;
}

