#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[11][11];
int check[11][11];
int parent[11];
int level[11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
map<pair<int, int>, int> ma;

void dfs(int x, int y, int color) {
    check[x][y] = 1;
    a[x][y] = color;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == 1) {
            dfs(nx, ny, color);
        }
    }
}

void go(int x, int y, int myColor, int dr, int dist) {
    if (a[x][y] != 0 && a[x][y] != myColor) {
        if (dist >= 2) {
            int coor1 = a[x][y], coor2 = myColor;
            if (coor1 > coor2) swap(coor1, coor2);
            if (ma[{coor1, coor2}] == 0 || ma[{coor1, coor2}] > dist) {
                ma[{coor1, coor2}] = dist;
            }
        }
        return;
    }
    if (dr == -1) {
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx <= n && 0 <= ny && ny < m && a[nx][ny] != myColor) {
                go(nx, ny, myColor, k, dist + 1);
            }
        }
    } else {
        int nx = x + dx[dr];
        int ny = y + dy[dr];
        if (0 <= nx && nx <= n && 0 <= ny && ny < m && a[nx][ny] != myColor) {
            go(nx, ny, myColor, dr, dist + 1);
        }
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (level[x] > level[y])
        swap(x, y);
    else if (level[x] == level[y])
        level[y]++;
    parent[x] = y;
    return true;
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
    int color = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 0 && a[i][j] == 1) {
                dfs(i, j, color++);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                go(i, j, a[i][j], -1, -1);
            }
        }
    }
    vector<tuple<int, int, int>> edge;
    for (auto mav : ma) {
        edge.push_back({mav.second, mav.first.first, mav.first.second});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < color; i++) {
        parent[i] = i;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        auto [q, w, e] = edge[i];
        if (merge(w, e)) {
            ans += q;
            cnt++;
        }
    }
    if (cnt == color - 2) {
        cout << ans;
        return 0;
    }
    cout << -1;
}