#include <math.h>

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::string;
using std::pair;

class Point
{
public:
    Point(int ix, int iy) : _ix(ix), _iy(iy) {}
    ~Point() {}
    double getDistance() const { return sqrt(_ix * _ix + _iy * _iy);}
    friend std::ostream& operator<<(std::ostream& os, const Point& rpt);
private:
    int _ix;
    int _iy;
};
std::ostream& operator<<(std::ostream& os, const Point& rpt)
{
    os << "(" << rpt._ix << ", " << rpt._iy << ")";
    return os;
}

struct PointComparator {
    bool operator()(const Point& rpt, const Point& lpt) const
    {
        return rpt.getDistance() < lpt.getDistance();
    }
};

template <typename Map>
void print_map(const Map & m) 
{
    cout << "{ ";
    for (auto & e : m) {// can deduce the const and not const
        cout << e.first << ":" << e.second << " ";
    }
    cout << "}" << endl;
}

void test0()
{
    //cout << "-----------------Default constructor--------------" << endl;
    //map<string, int> map1;
    //map1["something"] = 111;
    //map1["anything"] = 222;
    //map1["that thing"] = 666;
    //print_map(map1);
    //
    //cout << "-----------------Range(iterator) constructor--------------" << endl;
    //map<string, int> mapRange(map1.find("something"), map1.end()); 
    //print_map(mapRange);
    //
    //cout << "-----------------copy constructor--------------" << endl;
    //map<string, int> copyMap(map1);
    //print_map(copyMap);
    //
    //cout << "-----------------move constructor--------------" << endl;
    //map<string, int> moveMap(std::move(copyMap));
    //cout << "moveMap : "; print_map(moveMap);
    //cout << "copyMap : ";print_map(copyMap);
    //
    //cout << "-----------------initializer list constructor--------------" << endl;
    //map<string, int> initMap{
    //    pair<string, int>("be", 121),
    //    pair<string, int>("can", 565),
    //    pair<string, int>("only", 147)
    //};
    //print_map(initMap);
    map<string, int> initMap{
        {"haha", 12},
        {"wait", 46},
        std::make_pair("think", -45)
    };
    print_map(initMap);

    cout << "-----------------customize constructor--------------" << endl;
    map<Point, int, PointComparator> customize{
        {Point(1, 2), 8},
        {Point(5, 2), 8},
        {Point(9, 2), 8},
        {Point(7, 2), 8}
    };
    print_map(customize);
}

int main()
{
    test0();

    return 0;
}

