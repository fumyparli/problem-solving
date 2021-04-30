#include <bits/stdc++.h>
using namespace std;

int n, m, d;
vector<vector<int>> a(16, vector<int>(16));
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void downAll(vector<vector<int>> &b) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (i == 0)
                b[i][j] = 0;
            else
                b[i][j] = b[i - 1][j];
        }
    }
}

int check[16][16];
void bfs(int x, int y, vector<vector<int>> &b, map<pair<int, int>, int> &whokill) {
    memset(check, -1, sizeof(check));
    check[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (check[x][y] >= d) return;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (b[nx][ny] == 1) {
                    whokill[{nx, ny}] = check[x][y] + 1;
                    return;
                }
                if (check[nx][ny] == -1) {
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int maxKill = 0;
vector<int> bt;
void foo(int x) {
    if (bt.size() == 3) {
        auto b = a;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> whokill;
            for (auto y : bt) {
                bfs(n, y, b, whokill);
            }
            for (auto k : whokill) {
                b[k.first.first][k.first.second] = 0;
            }
            tmp += whokill.size();
            downAll(b);
        }
        maxKill = max(maxKill, tmp);
        return;
    }

    for (int i = x; i < m; i++) {
        bt.push_back(i);
        foo(i + 1);
        bt.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    foo(0);
    cout << maxKill;
}