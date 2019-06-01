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
using std::multimap;

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
    cout << "-----------------customize constructor--------------" << endl;
    multimap<Point, int, PointComparator> customize{
        {Point(1, 2), 8},
        {Point(1, 2), 8},
        {Point(5, 2), 8},
        {Point(9, 2), 8},
        {Point(1, 2), 8},
        {Point(5, 2), 8},
        {Point(7, 2), 8}
    };
    print_map(customize);
    
    //cout << "-----------------customize constructor--------------" << endl;
    //pair<map<Point, int>::iterator, bool> retPair = customize.insert({{7, -9}, -888}); 
    
    cout << "-----------------customize insert--------------" << endl;
    auto retPair = customize.insert({{5, 2}, 8}); 
    cout << "insert success" << endl;
    cout << retPair->first << "--->" << retPair->second << endl;
    print_map(customize);

    //cout << "insert by key" << endl;
    //customize[{4, 899}] = 789;
    ////customize[Point(4, 899)] = 789;
    //print_map(customize);
    
    //cout << "-----------------customize query--------------" << endl;
    //cout << "query by index" << endl;
    //cout << customize[Point(4, 899)] << endl;

    //cout << "query by index if not exist" << endl;
    //cout << customize[Point(4, 7878)] << endl;
    //print_map(customize);
    
    cout << "-----------------customize find--------------" << endl;
    map<Point, int>::iterator iterFind = customize.find(Point(1, 2));
    if (iterFind != customize.end()) {
        cout << "find it" << endl;
        cout << iterFind->first << "-->" << iterFind->second << endl;
    } else {
        cout << "not find it" << endl;
        cout << iterFind->first << "-->" << iterFind->second << endl;
    }
    cout << "after find" << endl;
    print_map(customize);
    
    cout << "-----------------customize count--------------" << endl;
    size_t cnt = customize.count(Point(1, 2));
    cout << "count: " << cnt << endl;

    cout << "-----------------customize lower_bound & upper_bound--------------" << endl;
    auto lowIter = customize.lower_bound(Point(1, 2));
    auto upperIter = customize.upper_bound(Point(1, 2));
    while (lowIter != upperIter) {
        cout << lowIter->first << "--->" << lowIter->second << endl;
        ++lowIter;
    }
    cout << "-----------------customize equal_range--------------" << endl;
    pair<multimap<Point, int>::iterator, multimap<Point, int>::iterator> rangeIter = customize.equal_range(Point(1, 2));
    while (rangeIter.first != rangeIter.second) {
        cout << rangeIter.first->first << "--->" << rangeIter.second->second << endl;
        ++rangeIter.first;
    }
}

int main()
{
    test0();

    return 0;
}

