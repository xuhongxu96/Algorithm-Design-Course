#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template <class T>
class MinHeap {
    T *data;
    int size;
    int maxSize;
    void shiftDown(int start, int m) {
        int j = start * 2 + 1;
        T temp = data[start];
        while (j <= m) {
            if (j < m && data[j] > data[j + 1]) ++j;
            if (temp < data[j]) break;
            data[start] = data[j];
            start = j;
            j = j * 2 + 1;
        }
        data[start] = temp;
    }
    void shiftUp(int start) {
        int j = (start - 1) >> 1;
        T temp = data[start];
        while (j > 0) {
            if (temp >= data[j]) break;
            data[start] = data[j];
            start = j;
            j = (j - 1) >> 1;
        }
        data[start] = temp;
    }
public:
    MinHeap(int sz = 20) : maxSize(sz), size(0) {
        data = new T[sz];
    }
    MinHeap(T arr[], int sz) : maxSize(sz * 2), size(sz) {
        data = new T[maxSize];
        memcpy(data, arr, sz * sizeof(T));
        int currentPos = (sz - 2) / 2;
        while (currentPos >= 0) {
            shiftDown(currentPos, sz - 1);
            --currentPos;
        }
    }
    void sort() {
        int sz = size;
        for (int i = 0; i < size; ++i) {
            T temp = data[--sz];
            data[sz] = data[0];
            data[0] = temp;
            shiftDown(0, sz - 1);
        }
    }
    T *begin() {
        return data;
    }
    T *end() {
        return data + size;
    }
    void push(const T&x) {
        if (size < maxSize) {
            data[size] = x;
            shiftUp(size);
            ++size;
        } else {
            T *temp = new T[size * 2];
            memcpy(temp, data, size * sizeof(T));
            size *= 2;
            delete [] data;
            data = temp;
        }
    }
};

int main(int argc, char **argv) {
    if (argc != 3) return -1;
    int cmd = 0;
    int N; 
    sscanf(argv[1], "%d", &cmd);
    sscanf(argv[2], "%d", &N);
    int *arr = new int[N];
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        arr[i] = rand();
    }
    if (cmd == 0) {
        MinHeap<int> heap(arr, N);
        heap.sort();
    } else if (cmd == 1) {
        for (int i = 1; i < N; ++i) {
            for (int j = i; j > 0; --j) {
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
        }
    } else {
        sort(arr, arr + N);
    }
    return 0;
}
