#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int check[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        pair<int, int> st;
        queue<tuple<int, int, int>> q;
        memset(a, 0, sizeof(a));
        memset(check, -1, sizeof(check));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '@') {
                    st = {i, j};
                }
                if (a[i][j] == '*') {
                    check[i][i] = -2;
                    q.push({i, j, 1});
                }
            }
        }
        q.push({st.first, st.second, 0});
        check[st.first][st.second] = 1;
        int flag = 0;
        while (!q.empty()) {
            auto [x, y, o] = q.front();
            q.pop();
            if (o == 0 && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
                cout << check[x][y] << '\n';
                flag = 1;
                break;
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx <= n && 0 <= ny && ny < m && a[nx][ny] == '.') {
                    if (check[nx][ny] == -1) {
                        if (o == 1) {
                            check[nx][ny] = -2;
                        } else {
                            check[nx][ny] = check[x][y] + 1;
                        }
                        q.push({nx, ny, o});
                    }
                }
            }
        }
        if (flag == 0) cout << "IMPOSSIBLE" << '\n';
    }
}