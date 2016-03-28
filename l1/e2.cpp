#include <iostream>
#include <cstring>
#include <utility>
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

    // Warnsdorf's Rule
    pair<int, int> weight[8];
    for (int ii = 0; ii < 8; ++ii) {
        int tx = x + dir[ii][0];
        int ty = y + dir[ii][1];
        weight[ii].second = ii;
        if (isIn(tx, ty) && g[tx][ty] == 0) {
            for (int j = 0; j < 8; ++j) {
                int ttx = tx + dir[j][0];
                int tty = ty + dir[j][1];
                if (ttx != x && tty != y && isIn(ttx, tty) && g[ttx][tty] == 0) {
                    ++weight[ii].first;
                }
            }
        }
    }
    sort(weight, weight + 8);

    for (int ii = 0; ii < 8; ++ii) {
        int j = weight[ii].second;
        int tx = x + dir[j][0];
        int ty = y + dir[j][1];
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
