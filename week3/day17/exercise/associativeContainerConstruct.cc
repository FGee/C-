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
    Point(int ix, int iy) : _ix(ix), _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }
    ~Point() { cout << "~Point()" << endl; }
    double getDistance() const { return sqrt(_ix * _ix + _iy * _iy);}
    friend std::ostream& operator<<(std::ostream& os, const Point& rpt);
private:
    int _ix;
    int _iy;
};
std::ostream& operator<<(std::ostream& os, const Point& rpt)
{
    os << rpt._ix << "--->" << rpt._iy << endl;
    return os;
}

bool operator<(const Point& rpt, const Point& lpt) //std::less<Point>
{
    return rpt.getDistance() < lpt.getDistance();
}

bool operator>(const Point& rpt, const Point& lpt) //std::less<Point>
{
    return rpt.getDistance() > lpt.getDistance();
}

struct PointComparator {
    bool operator()(const Point& rpt, const Point& lpt)
    {
        return rpt.getDistance() > lpt.getDistance();
    }
};

template <typename container>
void display(const container& con)
{
    //for (auto & elem : con) {
    //    cout << elem << endl;
    //}
    //typename container::const_iterator bg = con.begin();
    auto bg = con.begin();
    while (bg != con.end()) {
        cout << *bg << endl;
        ++bg;
    }
}

void test0()
{
    cout << "----------------default constructor--------------------" <<  endl;
    set<int> numbers0;
    display(numbers0);

    cout << "----------------initializer list constructor--------------------" <<  endl;
    set<int> numbers{ 1, 3, 5, 5, 6, 6, 7, 3 };
    display(numbers);

    cout << "----------------iterator constructor--------------------" <<  endl;
    set<int> numbers1(numbers.find(3), numbers.end());
    display(numbers1);

    cout << "----------------copy constructor--------------------" <<  endl;
    set<int> numbers2(numbers);
    display(numbers);

    cout << "----------------move constructor--------------------" <<  endl;
    set<int> numbers3(std::move(numbers1));
    display(numbers3);

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
}

void test1()
{
    std::pair<int, string> value(1, "hello");
    cout << value.first << "--->" << value.second << endl;
}

int main()
{
    test0();
    //test1();

    return 0;
}

