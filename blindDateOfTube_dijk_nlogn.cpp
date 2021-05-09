#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tllll = tuple<ll, ll, ll, ll>;
using vtllll = vector<tllll>;
using vvtllll = vector<vtllll>;
#define inf 9'000'000'000'000'000'000
ll d[51][51];
vector<int> solution(int n, int m, int s, vector<vector<int>> a) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            d[i][j] = inf;
        }
    }
    priority_queue<tllll, vtllll, greater<tllll>> pq;
    d[0][0] = 0;
    pq.push({0, 0, 0, 0});
    while (!pq.empty()) {
        auto [l, c, x, y] = pq.top();
        pq.pop();
        if (c <= s && x == n - 1 && y == m - 1) {
            return {(int)l, (int)d[x][y]};
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != -1) {
                if (d[nx][ny] > d[x][y] + a[nx][ny]) {
                    d[nx][ny] = d[x][y] + a[nx][ny];
                    pq.push({l + 1, d[nx][ny], nx, ny});
                }
            }
        }
    }
}