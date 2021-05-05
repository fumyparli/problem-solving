#include <bits/stdc++.h>
using namespace std;
#define inf 2'000'000'000
bool foo(int x, int y, int &n, int &d, int &maxv, int cnt, vector<vector<int>> a) {
    if (cnt >= maxv) return true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    a[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] > a[x][y] + 1) {
                a[nx][ny] = a[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] >= d) {
                if (foo(i, j, n, d, maxv, cnt + 1, a)) return true;
                return false;
            }
        }
    }
    return false;
}
int solution(int n, int m, vector<vector<int>> timetable) {
    int t[1321] = {0};
    for (int i = 0; i < m; i++) {
        t[timetable[i][0]]++;
        t[timetable[i][1] + 1]--;
    }
    int maxv = 0, cnt = 0;
    for (int i = 600; i <= 1320; i++) {
        cnt += t[i];
        maxv = max(maxv, cnt);
    }
    if (maxv <= 1) return 0;
    for (int k = 2 * (n - 1); k >= 1; k--) {
        for (int i = 0; i < n / 2; i++) {
            vector<vector<int>> a(n, vector<int>(n, inf));
            if (foo(0, i, n, k, maxv, 1, a)) return k;
        }
    }
}