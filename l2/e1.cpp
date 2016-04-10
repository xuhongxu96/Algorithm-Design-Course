#include <iostream>
using namespace std;

int n;
int *arr = nullptr;
int m;

int bisearch(int begin, int end, int t) {
    while (begin <= end) {
        int mid = (begin + end) >> 1;
        if (arr[mid] < t) {
            begin = mid + 1;
        } else if (arr[mid] > t) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> m;

    cout << bisearch(0, n, m) << endl;

    delete [] arr;

    return 0;
}
