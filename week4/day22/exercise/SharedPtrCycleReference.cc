#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::weak_ptr;

class Child;
class Parent
{
public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << _spChild.use_count() << endl; cout << "~Parent()" << endl; }
    weak_ptr<Child> _spChild;
};
class Child
{
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }
    shared_ptr<Parent> _spParent;
};

int main()
{
    std::shared_ptr<Parent> pParent(new Parent);
    std::shared_ptr<Child> pChild(new Child);

    pParent->_spChild = pChild;
    pChild->_spParent = pParent;

    return 0;
}

