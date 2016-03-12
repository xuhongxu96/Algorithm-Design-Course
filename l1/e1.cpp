#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int graph[10][10];
int min_p[10];
int p[10];

int calc_distance() {
    int d = 0;
    for (int i = 0; i < n - 1; ++i) {
        d += graph[p[i]][p[i + 1]];
    }
    return d;
}

int main() {
    int min_d = -1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    }
    while (true) {
        int i;
        int d = calc_distance();
        if (min_d == -1 || d < min_d) {
            min_d = d;
            memcpy(min_p, p, 10);
        }
        for (i = n - 1; i >= 0; --i) {
            if (p[i] < p[i + 1]) {
                for (int j = n - 1; j > i; --j) {
                    if (p[j] > p[i]) {
                        swap(p[i], p[j]);
                        reverse(p + i + 1, p + n);
                        d = calc_distance();
                        if (min_d == -1 || d < min_d) {
                            min_d = d;
                            memcpy(min_p, p, 10);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (i == -1) break;
    }
    for (int i = 0; i < n; ++i) {
        cout << min_p[i] << " ";
    }
    cout << endl;
    cout << min_d << endl;

    return 0;
}
