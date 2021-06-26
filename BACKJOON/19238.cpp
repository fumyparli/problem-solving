#include<bits/stdc++.h>
using namespace std;

int a[21][21][2];
int n, m, fuel;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int check[21][21];
int x, y;

struct C {
    int x1, y1, x2, y2, d;
};
vector<C> v;

struct Q {
    int x, y, d;
};
vector<C> v2;

int bfs(int x1, int y1, int d, int flag, int destx, int desty) {
    memset(check, 0, sizeof(check));
    v2.resize(0);
    int min = 987654321;
    queue<Q> q;
    q.push({x1, y1, d});
    check[x1][y1] = 1;
    while (!q.empty()) {
        x1 = q.front().x;
        y1 = q.front().y;
        d = q.front().d;
        q.pop();
        int x2 = v[a[x1][y1][1]].x2;
        int y2 = v[a[x1][y1][1]].y2;
        if (flag == 0 && a[x1][y1][0] == 2) {
            if (min >= d) {
                min = d;
                v2.push_back({x1, y1, x2, y2, d});
            }
        }
        if (flag == 1 && x1 == destx && y1 == desty) {
            x = destx;
            y = desty;
            return d;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x1 + dx[k];
            int ny = y1 + dy[k];
            if (0 < nx && 0 < ny && nx <= n && ny <= n && check[nx][ny] == 0 && a[nx][ny][0] != 1) {
                check[nx][ny] = 1;
                q.push({nx, ny, d + 1});
            }
        }
    }
    if (flag == 0 && min != 987654321) {
        return 0;
    }
    return -1;
}

void set_min(int &mind, int &minx, int &miny, int j) {
    mind = v2[j].d;
    minx = v2[j].x1;
    miny = v2[j].y1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> fuel;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j][0];
        }
    }
    cin >> x >> y;
    v.push_back({0, 0, 0, 0, 0});
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, y1, x2, y2, 0});
        a[x1][y1][0] = 2;
        a[x1][y1][1] = i;
    }
    for (int i = 1; i <= m; i++) {
        int mind = 987654321;
        int minx = 987654321;
        int miny = 987654321;
        int destx, desty;
        int d1 = bfs(x, y, 0, 0, 0, 0);
        if (d1 == -1) {
            cout << -1;
            return 0;
        }
        for (int j = 0; j < v2.size(); j++) {
            if (mind == v2[j].d) {
                if (minx == v2[j].x1) {
                    if (miny > v2[j].y1) {
                        set_min(mind, minx, miny, j);
                    }
                }
                if (minx > v2[j].x1) {
                    set_min(mind, minx, miny, j);
                }
            }
            if (mind > v2[j].d) {
                set_min(mind, minx, miny, j);
            }
        }
        x = minx;
        y = miny;
        destx = v[a[x][y][1]].x2;
        desty = v[a[x][y][1]].y2;
        a[x][y][0] = 0;
        int d2 = bfs(x, y, 0, 1, destx, desty);
        if (d2 == -1) {
            cout << -1;
            return 0;
        }
        if (mind + d2 > fuel) {
            cout << -1;
            return 0;
        } else {
            fuel -= mind + d2;
            fuel += 2 * d2;
        }
    }
    cout << fuel;
}