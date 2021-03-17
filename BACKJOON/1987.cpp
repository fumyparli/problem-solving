#include <bits/stdc++.h>
using namespace std;

int a[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, ans;

int check[26];

void foo(int x, int y, int level) {
    check[a[x][y] - 'A'] = 1;
    ans = max(ans, level);
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[a[nx][ny] - 'A'] == 0) {
            foo(nx, ny, level + 1);
            check[a[nx][ny] - 'A'] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }
    foo(0, 0, 1);
    cout << ans;
}