#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tllll = tuple<ll, ll, ll, ll>;
using vtllll = vector<tllll>;
using vvtllll = vector<vtllll>;
#define inf 9'000'000'000'000'000'000
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
ll d[51][51][2501];
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    swap(n, m);
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 2501; k++) {
                d[i][j][k] = inf;
            }
        }
    }
    priority_queue<tllll, vtllll, greater<tllll>> pq;
    d[0][0][0] = 0;
    pq.push({0, 0, 0, 0});
    while (!pq.empty()) {
        auto [c, l, x, y] = pq.top();
        pq.pop();
        if (c > s) continue;
        if (l > n * m) continue;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && time_map[nx][ny] != -1) {
                if (d[nx][ny][l + 1] > d[x][y][l] + time_map[nx][ny]) {
                    d[nx][ny][l + 1] = d[x][y][l] + time_map[nx][ny];
                    pq.push({d[nx][ny][l + 1], l + 1, nx, ny});
                }
            }
        }
    }
    for (int i = 0; i <= 2501; i++) {
        if (d[n - 1][m - 1][i] <= s) {
            return {i, (int)d[n - 1][m - 1][i]};
        }
    }
}