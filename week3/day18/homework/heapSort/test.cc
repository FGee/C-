#include "heapSort.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "----------------------int arr[5]------------------" << endl;
    int arr[5] = { 5, 7, 8, 9, 6 };
    HeapSort<int> hs(arr, 5);
    hs.sort();

    for (auto & e : arr) {
        cout << e << " ";
    }
    cout << endl;

    cout << "----------------------string strArr[5]------------------" << endl;
    string strArr[5] = { "haha", "xixi", "oioi", "cici", "uiui" };
    HeapSort<string, std::greater<string>> hsStr(strArr, 5);
    hsStr.sort();

    for (auto & e : strArr) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

