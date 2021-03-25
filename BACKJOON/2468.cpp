#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int check[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int l = 0; l < 100; l++) {
        memset(check, 0, sizeof(check));
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == 0 && a[i][j] > l) {
                    cnt++;
                    q.push({i, j});
                    check[i][j] = 1;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (0 <= nx && nx < n && 0 <= ny && ny < n && check[nx][ny] == 0 && a[nx][ny] > l) {
                                check[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}