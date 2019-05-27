#include <iostream>
#include <typeinfo>


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
    virtual
    void d()
    {
        cout << "B::d()" << endl;
    }
    float _fval = 6;
private:
};

class Typeinfo
{

};

void print()
{
    cout << "hi" << endl;
}

int main()
{
    Typeinfo type;
    A ca;
    int a = 3;
    float fval = 33.33;
    B* pb = new B;
    cout << "a type: " << typeid(a).name() << " hash code " << typeid(a).hash_code() << " before " << typeid(a).before(typeid(pb)) << endl;
    cout << "fval type: " << typeid(fval).name() << endl;
    cout << "ca type: " << typeid(ca).name() << endl;
    cout << "type type: " << typeid(type).name() << endl;
    cout << "pb type: " << typeid(*pb).name() << endl;
    return 0;
}

