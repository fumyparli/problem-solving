#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];
int check[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct info {
    int x;
    int y;
    int d;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'L')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(check, 0, sizeof(check));
            if (a[i][j] == 1) continue;
            queue<info> q;
            q.push({i, j, 0});
            check[i][j] = 1;
            while (!q.empty()) {
                info r = q.front();
                q.pop();
                ans = max(ans, r.d);
                for (int k = 0; k < 4; k++) {
                    int nx = r.x + dx[k];
                    int ny = r.y + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == 0) {
                        check[nx][ny] = 1;
                        q.push({nx, ny, r.d + 1});
                    }
                }
            }
        }
    }
    cout << ans;
}