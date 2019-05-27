#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Figure
{
public:
    Figure() { cout << "Figure()" << endl; }
    ~Figure() { cout << "~Figure()" << endl; }

    virtual void display() = 0;
private:
};

int main()
{
    Figure* pfig;


    return 0;
}

