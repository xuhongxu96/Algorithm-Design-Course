#include <iostream>
#include <cstring>
using namespace std;

int N;
const int dir[][2] = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
int m, n;
int g[10][10];
bool found = false;

bool isIn(int x, int y) {
    return x >= 0 && y >= 0 
        && x < N && y < N;
}

void dfs(int x, int y, int i) {
    if (found) return;
    if (i == N * N + 1) {
        found = true;
        for (int ii = 0; ii < N; ++ii) {
            for (int j = 0; j < N; ++j) {
                cout << g[ii][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int ii = 0; ii < 8; ++ii) {
        int tx = x + dir[ii][0];
        int ty = y + dir[ii][1];
        if (isIn(tx, ty) && g[tx][ty] == 0) {
            g[tx][ty] = i;
            dfs(tx, ty, i + 1);
            g[tx][ty] = 0;
        }
    }
}

int main() {
    cin >> N;
    cin >> m >> n;
    memset(g, 0, sizeof(g));
    g[m][n] = 1;
    dfs(m, n, 2);
    if (!found) cout << "no";
    return 0;
}
