#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int a[8][8];
int check[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
int width;
int ans = -1;
int a_one_num;

void dfs(int x, int y) {
    if (check[x][y] == 0) {
        check[x][y] = 1;
        width++;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (check[nx][ny] == 0 && a[nx][ny] == 0) {
                dfs(nx, ny);
            }
        }
    }
}

void foo(int x, int y, int wall) {
    if (wall == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) {
                    dfs(i, j);
                }
            }
        }
        ans = max(ans, ((n * m) - width - a_one_num - 3));
        width = 0;
        memset(check, 0, sizeof(check));
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 0 && a[i][j] == 0) {
                a[i][j] = 1;
                foo(i, j, wall + 1);
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                a_one_num++;
            }
        }
    }
    foo(0, 0, 0);
    cout << ans;
}