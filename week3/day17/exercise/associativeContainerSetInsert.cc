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
    set<Point, PointComparator> points{
        Point(1, 2),
        Point(1, 3),
        Point(5, 3),
        Point(2, 2),
        Point(1, 2),
        Point(2, 3)
    };
    display(points);
    //std::pair<set<Point, PointComparator>::iterator, bool> ret = points.insert(Point(2, 2));
    auto retPair = points.insert(Point(8, 8));
    if (retPair.second) {
        cout << "insert success" << endl;
        cout << *retPair.first << endl;
    } else {
        cout << "insert fail" << endl;
        cout << *retPair.first << endl;
    }

    cout << "----------------after insert--------------------" <<  endl;
    display(points);

    ////cout << points[5] << endl;
    //size_t cnt = points.count(Point(2, 2));
    //cout << "cnt = " << cnt << endl;

    //auto itFind = points.find(Point(2, 8));
    //if (itFind == points.end()) {
    //    cout << "not find it" << endl;
    //    cout << *itFind << endl;
    //} else {
    //    cout << "find it" << endl;
    //    cout << *itFind << endl;
    //}
    //cout << "----------------after find--------------------" <<  endl;
    //display(points);
}

int main()
{
    test0();

    return 0;
}

