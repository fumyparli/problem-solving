#include <bits/stdc++.h>
#define inf 700000000
using namespace std;
using pii = pair<int, int>;
int t, n, m;
char a[102][102];
int d[3][102][102];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pii> q;

void init_d(int o) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            d[o][i][j] = inf;
        }
    }
}

void bfs(int o) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n + 2 && 0 <= ny && ny < m + 2 && d[o][nx][ny] > d[o][x][y] && a[nx][ny] != '*') {
                if (a[nx][ny] == '#' && d[o][nx][ny] > d[o][x][y] + 1) {
                    d[o][nx][ny] = d[o][x][y] + 1;
                    q.push({nx, ny});
                } else if (a[nx][ny] != '#') {
                    d[o][nx][ny] = d[o][x][y];
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        vector<pii> st;
        cin >> n >> m;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                    a[i][j] = '.';
                } else {
                    cin >> a[i][j];
                    if (a[i][j] == '$') {
                        st.push_back({i, j});
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            init_d(i);
            d[i][st[i].first][st[i].second] = 0;
            q.push({st[i].first, st[i].second});
            bfs(i);
        }
        init_d(2);
        d[2][0][0] = 0;
        q.push({0, 0});
        bfs(2);
        int minv = inf;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                int tmp = d[0][i][j] + d[1][i][j] + d[2][i][j];
                if (a[i][j] == '#') tmp -= 2;
                if (minv > tmp) minv = tmp;
            }
        }
        cout << minv << '\n';
    }
}