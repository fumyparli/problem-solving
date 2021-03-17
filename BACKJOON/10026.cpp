#include <bits/stdc++.h>
using namespace std;

char a[101][101];
int check[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;
int rgb[26];

void foo(int x, int y) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (check[nx][ny] == 0 && (rgb[a[x][y] - 'A'] == rgb[a[nx][ny] - 'A']))
                foo(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    int ans1 = 0;
    rgb['B' - 'A'] = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == 0) {
                foo(i, j);
                ans1++;
            }
        }
    }
    int ans2 = 0;
    memset(check, 0, sizeof(check));
    rgb['G' - 'A'] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == 0) {
                foo(i, j);
                ans2++;
            }
        }
    }
    cout << ans2 << " " << ans1;
}