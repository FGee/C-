#include <iostream>

using std::cout;
using std::endl;

class Point2D {
public:
    Point2D(int ix = 0, int iy = 0) :
        _ix(ix),
        _iy(iy)
    {
        cout << "Point2D()" << endl;
    }
    ~Point2D() { cout << "~Point2D()" << endl; }
    void print()
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }
    int getY() { return _iy; }
protected:
    int _ix;
private:
    int _iy;
};

class Point3D :
    public Point2D 
{
public:
    Point3D(int ix = 0, int iy = 0, int iz = 0) :
        Point2D(ix, iy),
        _iz(iz)
    {
        cout << "Point3D()" << endl;
    }
    ~Point3D() { cout << "~Point3D()" << endl; }
    void print2D()
    {
        print();
    }
    void print()
    {
        cout << "(" << _ix << ", " << getY() << ", " << _iz << ")" << endl;
    }
protected:
    int _iz;
};

class Point4D :
    protected Point3D
{
public:
    Point4D(int ix, int iy, int iz, int t) :
        Point3D(ix, iy, iz),
        _t(t)
    {
        cout << "Point4D()" << endl;
    }
    ~Point4D() { cout << "~Point4D()" << endl; }
    void print() 
    {
        cout << "(" << _ix << ", " << getY() << ", " << _iz << ", " << _t << ")" << endl;
    }
private:
    int _t;
};

int main()
{


    return 0;
}
