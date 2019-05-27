#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct FunctionObject {
public:
    FunctionObject() = default;
    int operator()(int a, int b)
    {
        ++_cnt1;
        return a + b;
    }

    float operator()(float a, float b, float c)
    {
        ++_cnt2;
        return a * b * c;
    }

    int cnt1Get() { return _cnt1; }
    int cnt2Get() { return _cnt2; }
private:
    int _cnt1 = 0;
    int _cnt2 = 0;
};
    
int main()
{
    FunctionObject fo;
    cout << "----------one-----------" << endl;
    cout << "cnt1= " << fo.cnt1Get() << endl
        << "cnt2= " << fo.cnt2Get() << endl;

    fo(4, 5);
    fo(8, 7);
    fo(2.3, 8.9, 8.6);
    
    cout << "----------two-----------" << endl;
    cout << "cnt1= " << fo.cnt1Get() << endl
        << "cnt2= " << fo.cnt2Get() << endl;

    return 0;
}
