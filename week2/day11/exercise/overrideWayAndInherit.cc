#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Grandpa 
{
public:
    Grandpa(int grandpa) : _grandpa(grandpa) { cout << "Grandpa(int)" << endl; }
    ~Grandpa() { cout << "~Grandpa()" << endl; }
    virtual
        void print() const
        {
            cout << "_grandpa: " << _grandpa << endl;
        }
    void show()
    {
        print();
    }
private:
    int _grandpa;
};

class Parent
: public Grandpa// virtual(override is not match with private)
{
public:
    Parent(int grandpa, int parent) 
        : Grandpa(grandpa), _parent(parent)
    {
        cout << "Parent(int, int)" << endl;
    }
    ~Parent() { cout << "~Parent()" << endl; }
    //virtual
    void print() const //override
    {
        cout << "_parent: " << _parent << endl;
    }
private:
    int _parent;
};

class Child
: public Parent
{
public:
    Child(int grandpa, int parent, int child) 
        : Parent(grandpa, parent), _child(child)
    {
        cout << "Child(int, int, int)" << endl;
    }
    ~Child() { cout << "~Child" << endl; }
    virtual
    void print() const override
    {
        cout << "_child: " << _child << endl;
    }

private:
    int _child;
};

void display(Grandpa* pgrandpa)
{
    pgrandpa->print();
}

int main()
{
    //Grandpa grandpa(123456);
    //display(&Grandpa);

    //Parent der(2333, 666);
    //display(&der);

    //der.show();

    Child ch(1111, 2222, 3333);
    display(&ch);
    ch.print();
    cout << "-------------" << endl;
    ch.Grandpa::print();
    ch.Parent::print();
    ch.print();

    return 0;
}

