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
    long num = 2333;
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
    A a;
    long** ppvfptr = (long**)&a; 

    typedef void (*pFun)();
    pFun pf;
    pf = (pFun)(*ppvfptr)[0];
    cout << "A::a() = " << endl;
    pf();

    pf = (pFun)(*ppvfptr)[1];
    cout << "A::b() = " << endl;
    pf();
    
    pf = (pFun)(*ppvfptr)[2];
    cout << "A::b() = " << endl;
    pf();

    cout << "A::num = " << (long)ppvfptr[1] << endl;
    
    ppvfptr[1] = (long*)666;
    cout << "A::num = " << (long)ppvfptr[1] << endl;

    return 0;
}

