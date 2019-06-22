#include <iostream>
#include <functional>

using namespace std;

void add(int a, int b, int c) {
    a = b + c;
}

int main()
{
    using namespace placeholders;
    function<void(int, int)> cb = bind(add, 1, _1);

    return 0;
}


