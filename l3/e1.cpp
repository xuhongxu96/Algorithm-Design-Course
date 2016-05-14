#include <iostream>
#include <algorithm>
using namespace std;

int n;
int c;
int *w, *v;
int *f[2];
int **p;

void init() {
    cin >> n >> c;
    w = new int[n];
    v = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    f[0] = new int[c + 1];
    f[1] = new int[c + 1];
    p = new int*[n];
    for (int i = 0; i < n; ++i) {
        p[i] = new int[c + 1];
    }
}

void dispose() {
    delete [] w;
    delete [] v;
    delete [] f[0];
    delete [] f[1];
    for (int i = 0; i < n; ++i) {
        delete [] p[i];
    }
    delete [] p;
}

int main() {
    init();

    for (int i = 0; i <= c; ++i) {
        if (i >= w[n - 1]) {
            f[(n - 1) % 2][i] = v[n - 1];
            p[n - 1][i] = 1;
        }
        else {
            f[(n - 1) % 2][i] = 0;
            p[n - 1][i] = 0;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= c; ++j) {
            int r1 = f[(i + 1) % 2][j];
            if (j < w[i]) {
                f[i % 2][j] = r1;
                p[i][j] = 0;
            } else {
                int r2 = f[(i + 1) % 2][j - w[i]] + v[i];
                if (r1 < r2) {
                    f[i % 2][j] = r2;
                    p[i][j] = 1;
                } else {
                    f[i % 2][j] = r1;
                    p[i][j] = 0;
                }
            }
        }
    }
    cout << f[0][c] << endl;
    cout << "chosen indices" << endl;
    for (int i = 0; i < n; ++i) {
        if (p[i][c]) {
            c -= w[i];
            cout << i << endl;
        }
    }

    dispose();

    return 0;
}

