#include <bits/stdc++.h>
using namespace std;

int a[500][500];
int d[500][500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

int foo(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return 1;
    }
    if (d[x][y] != -1) {
        return d[x][y];
    }
    d[x][y] = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (a[nx][ny] < a[x][y]) {
                d[x][y] += foo(nx, ny);
            }
        }
    }
    return d[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << foo(0, 0);
}