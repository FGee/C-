#ifndef __LINE_H__  
#define __LINE_H__
#include <math.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Line {
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
        friend class Line;
    private:
        float _ix;
        float _iy;
    };

public:
    Line(float x1, float y1, float x2, float y2) : _pt1(x1, y1), _pt2(x2, y2)
    {
        cout << "Line(int x1, int y1, int x2, int y2)" << endl;
    }
    ~Line()
    {
        cout << "~Line()" << endl;
    }
    void print()
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

#endif
