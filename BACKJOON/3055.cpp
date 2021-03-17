#include <bits/stdc++.h>
using namespace std;

char a[51][51];
int check[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct info {
    int x;
    int y;
    int d;
    bool gowater;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, int> stgo;
    vector<pair<int, int>> stwater;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                stgo = {i, j};
            }
            if (a[i][j] == '*') {
                stwater.push_back({i, j});
            }
        }
    }
    queue<info> q;
    for (auto& i : stwater) {
        check[i.first][i.second] = 1;
        q.push({i.first, i.second, 0, 1});
    }
    check[stgo.first][stgo.second] = 1;
    q.push({stgo.first, stgo.second, 0, 0});
    while (!q.empty()) {
        info r = q.front();
        q.pop();
        if (a[r.x][r.y] == 'D' && r.gowater == 0) {
            cout << r.d;
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int nx = r.x + dx[k];
            int ny = r.y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] != '*' && a[nx][ny] != 'X') {
                if (!(a[nx][ny] == 'D' && r.gowater == 1)) {
                    check[nx][ny] = 1;
                    q.push({nx, ny, r.d + 1, r.gowater});
                }
            }
        }
    }
    cout << "KAKTUS";
}