#include <bits/stdc++.h>
using namespace std;

int a[301][301];
int check[301][301];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

void foo(int x, int y) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] != 0) {
            foo(nx, ny);
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
        int cnt = 0;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check[i][j] == 0 && a[i][j] != 0) {
                    cnt++;
                    foo(i, j);
                }
            }
        }
        if (cnt >= 2) {
            cout << ans;
            return 0;
        }

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) v.push_back({i, j});
            }
        }
        if (v.size() == n * m) {
            cout << 0;
            return 0;
        }
        for (auto& i : v) {
            for (int k = 0; k < 4; k++) {
                int nx = i.first + dx[k];
                int ny = i.second + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 0) {
                    a[nx][ny]--;
                }
            }
        }
        ans++;
    }
}