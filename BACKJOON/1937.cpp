#include <bits/stdc++.h>
using namespace std;

int a[500][500];
int d[500][500];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;

int dfs(int x, int y) {
    if (d[x][y]) return d[x][y];
    d[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && a[x][y] < a[nx][ny]) {
            d[x][y] = max(d[x][y], dfs(nx, ny) + 1);
        }
    }
    return d[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = dfs(i, j);
            if (answer < k) answer = k;
        }
    }
    cout << answer;
}