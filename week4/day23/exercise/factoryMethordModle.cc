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
    virtual
        Figure* create() = 0;
    virtual
        ~Factory() {}
};

class TrianlgeFactory
: public Factory
{
public:
    Figure* create()
    {
        return new Trianlge(3.2, 2.5, 5.7);
    }
};

class RectangleFactory
: public Factory
{
public:
    Figure* create()
    {
        return new Rectangle(3.5, 4.2);
    }
};

class CycleFactory
: public Factory
{
public:
    Figure* create()
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
    unique_ptr<TrianlgeFactory> upTriFact(new TrianlgeFactory);
    unique_ptr<Figure> upTri(upTriFact->create());
    show(upTri.get());

    unique_ptr<RectangleFactory> upRectFact(new RectangleFactory);
    unique_ptr<Figure> upRect(upRectFact->create());
    show(upRect.get());

    unique_ptr<CycleFactory> upCycleFact(new CycleFactory);
    unique_ptr<Figure> upCycle(upCycleFact->create());
    show(upCycle.get());

    return 0;
}

