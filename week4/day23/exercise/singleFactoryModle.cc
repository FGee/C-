#include <math.h>

#include <iostream>
#include <memory>

#define PI 3.14    

using std::cout;
using std::endl;
using std::cin;
using std::unique_ptr;

class Figure
{
public:
    virtual
        void display() = 0;
    virtual
        double area() = 0;
    virtual 
        ~Figure() {}
};

class Trianlge
: public Figure
{
public:
    Trianlge(double a, double b, double c) : _a(a), _b(b), _c(c) {}
    void display()
    {
        cout << "Triangle: ";
    }
    double area()  
    {
        double p = _a + _b + _c;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
private:
    double _a;
    double _b;
    double _c;
};

class Rectangle
: public Figure
{
public:
    Rectangle(double l, double w) : _lenth(l), _width(w) {}
    void display() 
    {
        cout << "Rectangle: ";
    }
    double area()
    {
        return _lenth * _width;
    }
private:
    double _lenth;
    double _width;
};

class Cycle 
: public Figure
{
public:
    Cycle(double r) : _r(r) {}
    void display() 
    {
        cout << "Cycle: ";
    }
    double area()
    {
        return PI * _r * _r; 
    }
private:
    double _r;
};

class Factory
{
public:
    static Trianlge* createTri()
    {
        return new Trianlge(3.2, 2.5, 5.7);
    }
    static Rectangle* createRect()
    {
        return new Rectangle(3.5, 4.2);
    }
    static Cycle* createCycle()
    {
        return new Cycle(2.5);
    }
};

void show(Figure* fig)
{
    fig->display();
    cout << fig->area() << endl;
}

int main()
{
    unique_ptr<Trianlge> upTri(Factory::createTri());
    show(upTri.get());

    unique_ptr<Rectangle> upRect(Factory::createRect());
    show(upRect.get());

    unique_ptr<Cycle> upCycle(Factory::createCycle());
    show(upCycle.get());

    return 0;
}

