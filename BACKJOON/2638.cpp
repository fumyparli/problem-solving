#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101][101];
int check[101][101];
int cheese[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (a[nx][ny] == 1) {
                cheese[nx][ny]++;
            }
            if (check[nx][ny] == 0 && a[nx][ny] == 0) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    while (true) {
        memset(cheese, 0, sizeof(cheese));
        memset(check, 0, sizeof(check));
        dfs(0, 0);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cheese[i][j] >= 2) {
                    a[i][j] = 0;
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            break;
        }
        ans++;
    }
    cout << ans;
}