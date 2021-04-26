#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int a[101][101];
int check[101][101];
int ccheck[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int &cnt2) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == 1 && ccheck[nx][ny] == 0) {
            ccheck[nx][ny] = 1;
            cnt2++;
        }
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == 0 && check[nx][ny] == 0) {
            dfs(nx, ny, cnt2);
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
    int prevcnt = 0;
    while (true) {
        int cnt2 = 0;
        memset(check, 0, sizeof(check));
        memset(ccheck, 0, sizeof(ccheck));
        dfs(0, 0, cnt2);
        if (cnt2 == 0) {
            cout << cnt << '\n'
                 << prevcnt;
            return 0;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (ccheck[i][j] == 1) {
                        a[i][j] = 0;
                    }
                }
            }
        }
        prevcnt = cnt2;
        cnt++;
    }
}