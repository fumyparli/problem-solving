#include <bits/stdc++.h>
using namespace std;
#define ti tuple<int, int, int>

int n, m;
int a[101][101];
int check[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }
    int ans = 2000000000;
    memset(check, -1, sizeof(check));
    queue<ti> q;
    q.push({0, 0, 0});
    check[0][0] = 0;
    while (!q.empty()) {
        ti r = q.front();
        q.pop();
        if (get<0>(r) == n - 1 && get<1>(r) == m - 1)
            ans = min(ans, get<2>(r));
        for (int k = 0; k < 4; k++) {
            int nx = get<0>(r) + dx[k];
            int ny = get<1>(r) + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && (check[nx][ny] == -1 || get<2>(r) + a[nx][ny] < check[nx][ny])) {
                check[nx][ny] = get<2>(r) + a[nx][ny];
                q.push({nx, ny, get<2>(r) + a[nx][ny]});
            }
        }
    }
    cout << ans;
}