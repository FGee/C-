#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::mem_fn;

class Number
{
public:
    Number(int n = 0) : _data(n) {}
    bool isEven()
    {
        return !(_data % 2);
    }
    bool isPrime()
    {
        if (_data <= 1) {
            return false;
        }
        for (int i = 2; i <= (_data / 2); ++i) {
            if (!(_data % i)) {
                return false;
            }
        }
        return true;
    }
    int getData()
    {
        return _data;
    }
    void display()
    {
        cout << _data << " ";
    }
private:
    int _data;
};

int main()
{
    vector<Number> nums;
    for (int i = 0; i < 10; ++i) {
        nums.push_back(i);
    }
    for_each(nums.begin(), nums.end(), mem_fn(&Number::display));
    cout << endl;

    nums.erase(remove_if(nums.begin(), nums.end(), mem_fn(&Number::isPrime)), nums.end());

    for_each(nums.begin(), nums.end(), mem_fn(&Number::display));
    cout << endl;


    return 0;
}

