#include <iostream>

#define PI 3.1415926
using std::cout;
using std::endl;

class Circle {
public:
    Circle() : _r() { cout << "Circle()" << endl; }
    Circle(double r) : _r(r) { cout << "Circle(double)" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
    double getArea()
    {
        return PI * _r * _r;
    }

    double getPerimeter()
    {
        return 2 * PI * _r;
    }

    void show()
    {
        cout << "r = " << _r << "; C = " << getPerimeter() << "; S = " << getArea() << endl;
    }

private: 
    double _r;
};

class Cylinder 
: protected Circle
{
public:
    Cylinder(double r, double h)
        : Circle(r), _h(h)
    {
        cout << "Cylinder(double, double)" << endl;
    }

    ~Cylinder() { cout << "~Cylinder()" << endl; }

    double getVolume()
    {
        return getArea() * _h;
    }
    
    void showVolume()
    {
        cout << "V = " << getVolume() << endl;
    }
private:
    double _h;
};

void test0()
{
    Circle cir;
    cir.show();

    Circle cir1(5.0);
    cir1.show();
}

void test1()
{
    Cylinder cyl(5.0, 10);
    cyl.showVolume();
}

int main()
{
    test0();
    test1();

    return 0;
}
