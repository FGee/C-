#include <math.h>

#include <iostream>

using std::cout;
using std::endl;

class Point {
public:
    Point(float ix = 0, float iy = 0) : _ix(ix), _iy(iy)
    {
        cout << "Point()" << endl;    
    }
    Point(const Point& pt) : _ix(pt._ix), _iy(pt._iy)
    {
        cout << "Point(const Point&)" << endl;
    }
    ~Point() { cout << "~Point()" << endl; }
    
    operator float()
    {
        cout << "operator float()" << endl;
        return sqrt(_ix * _ix + _iy * _iy);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& pt);
private:
    float _ix;
    float _iy;
};

class Complex {
public:
    Complex(float real_, float image) : _real(real_), _image(image) { cout << "Complex()" << endl; }
    ~Complex() { cout << "~Complex()" << endl; }
    friend std::ostream& operator<<(std::ostream& os, const Complex& cp);
    operator Point() 
    {
        return Point(this->_real, this->_image);
    }
private:
    float _real;
    float _image;
};

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    cout << "(" << pt._ix << ", " << pt._iy << ")";

    return os;
}
std::ostream& operator<<(std::ostream& os, const Complex& cp)
{
    cout << cp._real << " + " << cp._image << "i";
    return os;
}

int main()
{
    cout << endl << "-------------test one------------" << endl;
    Point pt;
    cout << "pt=" << pt << endl;
    pt = 3;
    cout << "pt=" << pt << endl;
    //float distan = pt;
    cout << "distance to origin = " << (float)pt << endl;;
    
    cout << endl << "-------------test one------------" << endl;
    Complex cp(2.3, 4.5);
    cout << cp << endl;
    pt = cp;
    cout << pt << endl;

    return 0;
}
