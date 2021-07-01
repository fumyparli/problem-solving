#include <iostream>
#include <queue>
using namespace std;

int a[101][101];
int d[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    d[1][1] = 0;
    int ans = 2147483647;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (a[x][y] == 2) {
            ans = min(ans, d[x][y] + (n - x + m - y));
        }
        if (x == n && y == m) {
            ans = min(ans, d[x][y]);
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
                if (a[nx][ny] != 1 && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    if (ans > t) {
        cout << "Fail";
    } else {
        cout << ans;
    }
}