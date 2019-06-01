#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

template <class CT>
class Transform
{
public:
    template <typename Iterator>
    Transform(Iterator begin, Iterator end)
    : _sz(end - begin), _pct(new CT[_sz]())
    {
        int index = 0;
        while(begin != end) {
            _pct[index] = *begin;
            ++begin;
            ++index;
        }
    }
    void print();
private:
    int _sz;
    CT* _pct;
};

template <class CT>
void Transform<CT>::print()
{
    for (int i = 0; i != _sz; ++i) {
        cout << _pct[i] << endl;
    }
}

int main()
{
    vector<char> vchar { 'h', 'e', 'l', 'l', 'o' };
    
    Transform<char> trInt(vchar.begin(), vchar.end());
    trInt.print();

    return 0;
}

