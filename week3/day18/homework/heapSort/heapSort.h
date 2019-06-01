#pragma once

#include <iostream>

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
    HeapSort(T* arr, int size) : _arr(arr), _size(size) {}
    void sort();
private:
    void heapAdjust(int, int);
private:
    T* _arr;
    int _size;
};

template <typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust(int low, int high)
{
    int i = low, j = 2 * i + 1;
    T tmp = _arr[i];
    while (j <= high) {
        if (j < high && _arr[j] < _arr[j + 1]) {
            ++j;
        }
        if (tmp < _arr[j]) {
            _arr[i] = _arr[j];
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    _arr[i] = tmp;
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
    for (int i = (_size / 2) - 1; i >= 0; --i) {
        heapAdjust(i, _size);
    }
    T tmp;
    for (int i = _size - 1; i >= 1; --i) {
        tmp = _arr[0];
        _arr[0] = _arr[i];
        _arr[i] = tmp;
        heapAdjust(0, i - 1);
    }
}
