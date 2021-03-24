#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
int a[1001][1001];
int check[11][1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct info {
    int x;
    int y;
    int d;
    int w;
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, maxw;
    cin >> n >> m >> maxw;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            for (int k = 0; k <= maxw; k++)
                check[k][i][j] = inf;
        }
    }
    queue<info> q;
    q.push({0, 0, 1, 0});
    check[0][0][0] = 1;
    int ans = inf;
    while (!q.empty()) {
        info r = q.front();
        q.pop();
        if (r.x == n - 1 && r.y == m - 1) ans = min(ans, r.d);
        for (int k = 0; k < 4; k++) {
            int nx = r.x + dx[k];
            int ny = r.y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (r.d + 1 < check[r.w][nx][ny]) {
                    if (a[nx][ny] == 1 && r.w < maxw) {
                        check[r.w][nx][ny] = r.d + 1;
                        q.push({nx, ny, r.d + 1, r.w + 1});
                    } else if (a[nx][ny] == 0) {
                        check[r.w][nx][ny] = r.d + 1;
                        q.push({nx, ny, r.d + 1, r.w});
                    }
                }
            }
        }
    }
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
}