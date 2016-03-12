#include <iostream>
#include <cstring>
using namespace std;

const int W = 8, H = 8;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;
int g[10][10];
bool found = false;

bool isIn(int x, int y) {
    return x >= 0 && y >= 0 
        && x < W && y < H;
}

void dfs(int x, int y, int i) {
    if (found) return;
    if (i == W * H + 1) {
        found = true;
        for (int ii = 0; ii < W; ++ii) {
            for (int j = 0; j < H; ++j) {
                cout << g[ii][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int ii = 0; ii < 4; ++ii) {
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
    cin >> m >> n;
    memset(g, 0, sizeof(g));
    g[m][n] = 1;
    dfs(m, n, 2);
    return 0;
}
