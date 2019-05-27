#include <string.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Computer {
public:
    Computer(char * name, int price) : _name(name), _price(price)
    {}
    void init(char *name, int price);
    void print();
    ~Computer()
private:
    string _name;
    float _price;
};

int main()
{
    Computer my();
    std::cout << "Hello world" << std::endl;
    return 0;
}

void Computer::init(char *name, int price)
{
    _name = name;
    _price = price;
}
void Computer::print()
{
    cout << "name :" << _name 
         << "price :" << _price
         << endl;
}

