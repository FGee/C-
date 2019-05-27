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
    virtual
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

class C
: public A,
    public B
{
public:
    void a()
    {
        cout << "C::a()" << endl;
    }
    void c()
    {
        cout << "C::c()" << endl;
    }
    void d()
    {
        cout << "C::d()" << endl;
    }
private:
};

class D
 : public C 
{
public:
    void c()
    {
        cout << "D::c()" << endl;
    }
private:
};

int main()
{
    //cout << "----------------C-------------------" << endl;
    //C c;
    //c.a();
    ////c.b();
    //c.c();
    //c.d();

    //cout << "----------------pA = &c-------------" << endl;
    //A* pA;
    //pA = &c;
    //pA->a();
    //pA->b();
    //pA->c();

    //cout << "----------------pB = &c-------------" << endl;
    //B* pB;
    //pB = &c;
    //pB->a();
    //pB->b();
    //pB->c();
    //pB->d();

    //cout << "----------------pB = &c-------------" << endl;
    //C* pC;
    //pC = &c;
    //pC->a();
    ////pC->b();
    //pC->c();
    //pC->d();

    //cout << "----------------pB = &c-------------" << endl;
    //D d;
    //pC = &d;
    //pC->c();
    //
    //cout << "----------------RTTI-------------" << endl;
    ////A* pa = (A*)new B;
    ////B* pb = (B*)pa;
    ////pb->a();

    cout << "----------------RTTI--------------" << endl;
    A* pa1 = new A;
    B* pb1 = (B*)pa1;
    pb1->d();

    return 0;
}

