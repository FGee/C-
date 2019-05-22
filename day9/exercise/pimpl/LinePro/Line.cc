#include "Line.h"

#include <math.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Line::LineImply {
    class Point {
    public:
        Point(float ix = 0, float iy = 0) : _ix(ix), _iy(iy) 
        {
            cout << "Point()" << endl;
        }
        ~Point()
        {
            cout << "~Point()" << endl;
        }

        void print()
        {
            cout << "(" << _ix << ", " << _iy << ")" << endl;
        }
        friend class LineImply;
    private:
        float _ix;
        float _iy;
    };

public:
    LineImply(float x1, float y1, float x2, float y2) : _pt1(x1, y1), _pt2(x2, y2)
    {
        cout << "LineImply(float x1, float y1, float x2, float y2)" << endl;
    }
    ~LineImply()
    {
        cout << "~LineImply()" << endl;
    }
    void printLine()
    {
        _pt1.print();
        cout << "---->" << endl;
        _pt2.print(); 
    }
    float distance()
    {
        return sqrt((_pt1._ix - _pt2._ix) * (_pt1._ix - _pt2._ix) + (_pt1._iy - _pt2._iy) * (_pt1._iy - _pt2._iy));
    }
private:
    Point _pt1;
    Point _pt2;
};

Line::Line(float x1, float y1, float x2, float y2) : _pLineImply(new LineImply(x1, y1, x2, y2))
{
    cout << "Line(float, float, float, float)" << endl;
}

Line::~Line()
{
    delete _pLineImply;
    cout << "~Line()" << endl;
}

void Line::printLine() const 
{
    _pLineImply->printLine();
}

float Line::distance() const 
{
    return _pLineImply->distance();
}
