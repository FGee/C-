#include <limits>
#include <math.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

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

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    cout << "(" << pt._ix << ", " << pt._iy << ")";

    return os;
}

class Complex {
public:
    Complex(float real_, float image) : _real(real_), _image(image) { cout << "Complex()" << endl; }
    ~Complex() { cout << "~Complex()" << endl; }
    friend std::ostream& operator<<(std::ostream& os, const Complex& cp);
    friend std::istream& operator>>(std::istream& is, Complex& cp);
    operator Point() 
    {
        return Point(this->_real, this->_image);
    }
private:
    float _real;
    float _image;
};

std::ostream& operator<<(std::ostream& os, const Complex& cp)
{
    cout << cp._real << " + " << cp._image << "i";
    return os;
}

void readDouble(std::istream& is, float& val)
{
    cout << " >>Pls input the float number: " << endl;
    while (is >> val, !is.eof()) {
        if (is.bad()) {
            cout << "istream crash" << endl;
            return;
        }
        if (is.fail()) {
            cout << " >>Pls input the float number: " << endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

std::istream& operator>>(std::istream& is, Complex& cp)
{
    readDouble(is, cp._real);
    readDouble(is, cp._image);
    return is;
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
    
    cout << endl << "-------------test one------------" << endl;
    cin >> cp;
    cout << cp << endl;

    return 0;
}
