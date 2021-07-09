#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int check[1001][1001];
int color[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
void foo(int x, int y, int &cnt, vector<pair<int, int>> &v) {
    check[x][y] = 1;
    cnt++;
    v.push_back({x, y});
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == 0) {
            foo(nx, ny, cnt, v);
        }
    }
}
int colorcnt;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && check[i][j] == 0) {
                colorcnt++;
                int cnt = 0;
                vector<pair<int, int>> v;
                foo(i, j, cnt, v);
                for (auto &r : v) {
                    check[r.first][r.second] = cnt;
                    color[r.first][r.second] = colorcnt;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                int ans = 1;
                set<int> colorcheck;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && colorcheck.find(color[nx][ny]) == colorcheck.end()) {
                        colorcheck.insert(color[nx][ny]);
                        ans += check[nx][ny];
                    }
                }
                cout << ans % 10;
            } else
                cout << 0;
        }
        cout << '\n';
    }
}