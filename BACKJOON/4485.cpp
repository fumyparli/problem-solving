#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;
using vpii = vector<tiii>;
using vvpii = vector<vpii>;
#define inf 2'000'000'000

int a[126][126];
int d[126][126];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
priority_queue<tiii, vpii, greater<tiii>> pq;
int cnt;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cnt++;
        int n;
        cin >> n;
        if (n == 0) return 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = inf;
                cin >> a[i][j];
            }
        }
        pq.push({0, 0, 0});
        d[0][0] = a[0][0];
        while (!pq.empty()) {
            auto [c, x, y] = pq.top();
            pq.pop();
            if (d[x][y] < c) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (d[nx][ny] > d[x][y] + a[nx][ny]) {
                        d[nx][ny] = d[x][y] + a[nx][ny];
                        pq.push({d[nx][ny], nx, ny});
                    }
                }
            }
        }
        cout << "Problem " << cnt << ": " << d[n - 1][n - 1] << '\n';
    }
}