#include <bits/stdc++.h>
using namespace std;

int a[21][21];
int n;
int sum[21];
int ans = 987654321;
int check[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    check[x][y] = 5;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && check[nx][ny] != 5) {
                check[nx][ny] = 5;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    cin >> n;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cin >> a[x][y];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {  // 기준점
            for (int d1 = 1; d1 <= n; d1++) {
                for (int d2 = 1; d2 <= n; d2++) {
                    if (1 <= x && x < x + d1 + d2 && x + d1 + d2 <= n && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n) {
                        memset(check, 0, sizeof(check));
                        for (int r = 1; r <= n; r++) {
                            for (int c = 1; c <= n; c++) {
                                if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
                                    check[r][c] = 1;
                                }
                                if (1 <= r && r <= x + d2 && y < c && c <= n) {
                                    check[r][c] = 2;
                                }
                                if (x + d1 <= r && r <= n && 1 <= c && c < y - d1 + d2) {
                                    check[r][c] = 3;
                                }
                                if (x + d2 < r && r <= n && y - d1 + d2 <= c && c <= n) {
                                    check[r][c] = 4;
                                }
                            }
                        }
                        for (int r = 0; r <= d1; r++) {
                            check[x + r][y - r] = 5;
                            check[x + d2 + r][y + d2 - r] = 5;
                        }
                        for (int r = 0; r <= d2; r++) {
                            check[x + r][y + r] = 5;
                            check[x + d1 + r][y - d1 + r] = 5;
                        }
                        for (int r = 0; r < d1; r++) {
                            bfs(x + r + 1, y - r);
                        }
                        for (int r = 0; r < d2; r++) {
                            bfs(x + r + 1, y + r);
                        }
                        memset(sum, 0, sizeof(sum));
                        for (int r = 1; r <= n; r++) {
                            for (int c = 1; c <= n; c++) {
                                sum[check[r][c]] += a[r][c];
                            }
                        }
                        int tmax = max({sum[1], sum[2], sum[3], sum[4], sum[5]});
                        int tmin = min({sum[1], sum[2], sum[3], sum[4], sum[5]});
                        if (ans > tmax - tmin) {
                            ans = tmax - tmin;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}