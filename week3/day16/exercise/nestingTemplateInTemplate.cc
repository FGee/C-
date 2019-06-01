#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <class T>
class Outside
{
public:
    template <class R>
    class Inside
    {
    public:
        Inside(R x) : _r(x) { cout << "Inside(R)" << endl; }
        void disp();
        //void disp() { cout << "Inside: " << _r << endl; }
    private:
        R _r;
    };
    Outside(T x) : _t(x) { cout << "Outside(T)" << endl; }
    void disp();
    //void disp() { cout << "Outside: "; _t.disp(); }
private:
    Inside<T> _t;
};

template <class T>
template <class R>
void Outside<T>::Inside<R>::disp()
{
    cout << "Inside: " << Outside<T>::Inside<R>::_r << endl;
}

template <class T>
void Outside<T>::disp()
{
    cout << "Outside: ";
    _t.disp();
}

int main()
{
    Outside<int>::Inside<double> obin(3.5);
    obin.disp();

    Outside<int> obout(2);
    obout.disp();

    return 0;
}

