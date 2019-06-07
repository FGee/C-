#include <math.h>

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::cin;

class Figure
{
    using DisplayCallBack = std::function<void()>;
    using AreaCallBack = std::function<double()>;
public:
    void setDisplayCallBack(DisplayCallBack d) { _display = d; }
    void setAreaCallBack(AreaCallBack a) { _area = a; }
    void handleDisplayCallBack()
    {
        if (_display) {
            _display();
        }
    }
    double handAreaCallBack()
    {
        if (_area) {
           return _area();
        } else 
            return -1.0;
    }
private:
    DisplayCallBack _display;
    AreaCallBack _area;
};

class Rectangle
{
public:
    Rectangle(size_t length, size_t width)
        : _length(length)
          , _width(width)
    {}

    void display() const 
    {   cout << "rectangle";    }

    double area() const
    {   return _length * _width;    }

private:
    size_t _length;
    size_t _width;

};

class Circle
{
public:
    Circle(double radius)
        : _radius(radius)
    {}

    void print() const
    {   cout << "circle";   }

    double getArea() const
    {   return 3.14159 * _radius * _radius; }

private:
    double _radius;

};

class Triangle
{
public:
    Triangle(size_t a, size_t b, size_t c)
        : _a(a)
          , _b(b)
          , _c(c)
    {}

    void show() const
    {   cout << "triangle"; }

    double calcArea() const
    {
        size_t p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));

    }

private:
    size_t _a;
    size_t _b;
    size_t _c;

};

void display(Figure* pfig) {
    pfig->handleDisplayCallBack();
    cout << " : " << pfig->handAreaCallBack() << endl;
}

int main()
{
    Figure fig;
    Triangle tri(7, 8, 9);
    Rectangle rect(8, 5);
    Circle circle(5.0);

    fig.setDisplayCallBack(std::bind(&Triangle::show, &tri));
    fig.setAreaCallBack(std::bind(&Triangle::calcArea, tri));
    display(&fig);
    
    fig.setDisplayCallBack(std::bind(&Rectangle::display, &rect));
    fig.setAreaCallBack(std::bind(&Rectangle::area, rect));
    display(&fig);

    fig.setDisplayCallBack(std::bind(&Circle::print, circle));
    fig.setAreaCallBack(std::bind(&Circle::getArea, &circle));
    display(&fig);

    return 0;
}

