#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Protected
{
public:
    Protected(double pro) : _pro(pro) 
    { cout << "Protected()" << endl; }
    ~Protected() { cout << "~Protected()" << endl; }

    void print()
    {
        cout << "_pro = " << _pro << endl;
    }
private:
    double _pro;
};

class Derive
: protected Protected
{
public:
    Derive(double pro, double derive) 
        : Protected(pro), _derive(derive)
    {
        cout << "Derive(double, double)" << endl;
    }
    ~Derive() { cout << "~Derive()" << endl; }

    void print()
    {
        Protected::print();
        cout << "_derive = " << _derive << endl;
    }
private:
    double _derive;
};

int main()
{
    //Protected pro; //abstract class; can not to imply
    Derive der(1111, 2222);
    der.print();

    return 0;
}

