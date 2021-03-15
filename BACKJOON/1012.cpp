#include <bits/stdc++.h>
using namespace std;

int a[51][51];
int check[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k;

void dfs(int x, int y) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int q, w;
            cin >> q >> w;
            a[q][w] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && check[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}