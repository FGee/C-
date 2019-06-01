#include <math.h>

#include <iostream>
#include <set>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::cin;
using std::set;
using std::string;
using std::multiset;

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

template <typename container>
void display(const container& con)
{
    for (auto & elem : con) {
        cout << elem << endl;
    }
}

void test0()
{
    cout << "----------------custom comparation--------------------" <<  endl;
    //set<Point, std::greater<Point>> points{
    multiset<Point, PointComparator> points{
        Point(1, 2),
        Point(1, 3),
        Point(5, 3),
        Point(2, 2),
        Point(1, 2),
        Point(2, 3)
    };
    display(points);
    //std::pair<set<Point, PointComparator>::iterator, bool> ret = points.insert(Point(2, 2));
    auto retIter = points.insert(Point(8, 8));
    cout << "insert elem: " << *retIter << endl; 

    cout << "----------------after insert--------------------" <<  endl;
    display(points);

    //cout << points[5] << endl;
    size_t cnt = points.count(Point(1, 2));
    cout << "cnt = " << cnt << endl;

    auto itFind = points.find(Point(1, 2));
    if (itFind == points.end()) {
        cout << "not find it" << endl;
        cout << *itFind << endl;
    } else {
        cout << "find it" << endl;
        cout << *itFind << endl;
    }
    cout << "----------------after find--------------------" <<  endl;
    display(points);

    cout << "----------------range search one--------------------" <<  endl;
    auto lowerIter = points.lower_bound(Point(1, 2));
    auto upperIter = points.upper_bound(Point(1, 2));
    while (lowerIter != upperIter) {
        cout << *lowerIter << endl;
        ++lowerIter;
    }
    
    cout << "----------------range search two--------------------" <<  endl;
    //std::pair<multiset<Point, PointComparator>::iterator, multiset<Point, PointComparator>::iterator> retPair = points.equal_range(Point(1, 2));
    auto retPair = points.equal_range(Point(1, 2));
    while(retPair.first != retPair.second) {
        cout << *retPair.first << endl;
        ++retPair.first;
    }
}

int main()
{
    test0();

    return 0;
}

