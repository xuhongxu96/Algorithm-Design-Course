#include <iostream>
using namespace std;

const int N = 100;
int n;
float a[N + 1];
float b[N];
float m[N][N];
float w[N][N];
float s[N][N];

void output_root(int root, int lb, int rb) {
    if (root > lb) {
        int l = s[lb][root - 1];
        cout << root << "'s left child: " << l << endl;
        output_root(l, lb, root - 1);
    }
    if (root < rb) {
        int r = s[root + 1][rb];
        cout << root << "'s right child: " << r << endl;
        output_root(r, root + 1, rb);
    }
}

int main() {

    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        m[i][i - 1] = a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        w[i][i - 1] = a[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            w[i][j] = w[i][j - 1] + a[j] + b[j];
            m[i][j] = w[i][j];
            float minv = -1;
            for (int k = i; k <= j; ++k) {
                float t = m[i][k - 1] + m[k + 1][j];
                if (minv == -1 || t < minv) {
                    minv = t;
                    s[i][j] = k;
                }
            }
            m[i][j] += minv;
        }
    }

    cout << m[1][n] << endl;

    int k = s[1][n];
    vis[k] = true;
    cout << "root: " << k << endl;
    output_root(k, 1, n);
    return 0;
}
