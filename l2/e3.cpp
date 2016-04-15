//
// Created by xuhongxu on 16/4/15.
//
#include <iostream>
using namespace std;

int n;
int *arr;

void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void bubbleSort(int p, int r) {
    bool isSwapped = true;
    while (isSwapped) {
        isSwapped = false;
        for (int i = p; i < r; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(i, i + 1);
                isSwapped = true;
            }
        }
    }
}

int partition(int p, int r, int x) {
    int ret = -1, i, j;
    for (i = p, j = r; i < j; ) {
        if (arr[i] < x) {
            ++i;
        } else if (arr[i] > x) {
            swap(i, j);
            --j;
        } else {
            swap(i, j);
            ret = j;
            --j;
        }
    }
    if (ret == -1) throw "Err";
    swap(ret, i);
    return i;
}

int select(int p, int r, int k) {
    if (r - p < 5) {
        bubbleSort(p, r);
        return arr[p + k - 1];
    }
    for (int i = 0; i <= (r - p - 4) / 5; ++i) {
        int s = p + 5 * i;
        int t = s + 4;
        bubbleSort(s, t);
        swap(p + i, s + 2);
    }
    int x = select(p, p + (r - p - 4) / 5, (r - p + 6) / 10);
    int i = partition(p, r, x);
    int j = i - p + 1;
    if (k <= j) {
        return select(p, i, k);
    } else {
        return select(i + 1, r, k - j);
    }

}

int kthElement(int k) {
    return select(0, n - 1, k);
}

int main() {
    while (1) {
        cin >> n;
        if (n == -1) break;
        arr = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int k;
        cin >> k;
        cout << kthElement(k);

        delete[] arr;
    }
    return 0;
}
