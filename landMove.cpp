#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int team[301][301];
int parent[90001];
int level[90001];
int t_idx = 1, n, h;
vector<vector<int>> a;

void dfs(int x, int y, int t) {
    team[x][y] = t;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && team[nx][ny] == 0 && abs(a[nx][ny] - a[x][y]) <= h) {
            dfs(nx, ny, t);
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
    if (x == y) return 0;
    if (level[x] > level[y]) swap(x, y);
    parent[x] = y;
    if (level[x] == level[y]) level[y]++;
    return 1;
}

int solution(vector<vector<int>> land, int height) {
    n = land.size();
    a = land;
    h = height;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (team[i][j] == 0) {
                dfs(i, j, t_idx++);
            }
        }
    }
    set<int> t_cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t_cnt.insert(team[i][j]);
        }
    }
    int m = t_cnt.size();
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                int t1 = team[i][j];
                int t2 = team[i][j + 1];
                if (t1 != t2) {
                    pq.push({-abs(a[i][j] - a[i][j + 1]), t1, t2});
                }
            }
            if (i + 1 < n) {
                int t1 = team[i][j];
                int t2 = team[i + 1][j];
                if (t1 != t2) {
                    pq.push({-abs(a[i][j] - a[i + 1][j]), t1, t2});
                }
            }
        }
    }
    for (int i = 0; i < 90001; i++) {
        parent[i] = i;
    }
    int cnt = 0, ans = 0;
    while (!pq.empty()) {
        auto [c, x, y] = pq.top();
        pq.pop();
        if (merge(x, y)) {
            cnt++;
            ans += c;
        }
        if (cnt == m - 1) break;
    }
    return -ans;
}