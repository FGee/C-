#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

class Animal
{
public:
    virtual
        void say() = 0;
private:
};

class Dog
: public Animal
{
public:
    void say()
    {
        cout << "wang wang~ ~" << endl;
    }
    void fill()
    {
        cout << "Shake the tail" << endl;
    }
private:
};

class Cat
: public Animal
{
public:
    void say()
    {
        cout << "miao miao~ ~" << endl;
    }
    void play()
    {
        cout << "play the ball of yarn" << endl;
    }
private:
};

void verify(Animal* pani)
{
    if (typeid(*pani) == typeid(Dog)) {
        cout << "dog" << endl;
        dynamic_cast<Dog*>(pani)->say();
        dynamic_cast<Dog*>(pani)->fill();
    }
    if (typeid(*pani) == typeid(Cat)) {
        cout << "cat" << endl;
        dynamic_cast<Cat*>(pani)->say();
        dynamic_cast<Cat*>(pani)->play();
    }
}

int main()
{
    Dog dog;
    verify(&dog);

    Cat cat;
    verify(&cat);

    return 0;
}

