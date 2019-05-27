#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Base
{
public:
    Base(double base) : _pBase(new double(base))
    {
        cout << "Base(double)" << endl; 
    }
    
    virtual
    ~Base()
    {
        delete _pBase;
        cout << "~Base()" << endl; 
    }

    //virtual
    void print()
    {
        cout << "*_pBase = " << *_pBase << endl;
    }
private:
    double* _pBase;
};

class Derive
: public Base 
{
public:
    Derive(double base, double der)
        : Base(base), _derive(new double(der))
    {
        cout << "Derive(double, double)" << endl;
    }

    ~Derive()
    {
        delete _derive;
        cout << "~Derive()" << endl;
    }
    void print()
    {
        Base::print();
        cout << "*_derive = " << *_derive << endl;
    }
private:
    double* _derive;
};

int main()
{
    //Derive der(11.11, 12.12);
    //der.print();
    
    Base* pBase = new Derive(11.11, 12.12);
    pBase->print();

    delete pBase;

    return 0;
}

