#include <bits/stdc++.h>
using namespace std;

int a[50][50];
int d[50][50];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
vector<int> x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
            a[i][j] = d[i][j];
            if (d[i][j] == -1) {
                x.push_back(i);
            }
        }
    }

    int x1 = x[0];
    int x2 = x[1];
    while (t--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = a[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    if (d[i][j] == -1)
                        continue;
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && d[nx][ny] != -1) {
                        int tmp = d[i][j] / 5;
                        a[i][j] -= tmp;
                        a[nx][ny] += tmp;
                    }
                }
            }
        }
        for (int i = x1; i > 0; i--) {
            a[i][0] = a[i - 1][0];
            a[i - 1][0] = 0;
        }
        for (int i = 0; i < m - 1; i++) {
            a[0][i] = a[0][i + 1];
            a[0][i + 1] = 0;
        }
        for (int i = 0; i < x1; i++) {
            a[i][m - 1] = a[i + 1][m - 1];
            a[i + 1][m - 1] = 0;
        }
        for (int i = m - 1; i > 0; i--) {
            a[x1][i] = a[x1][i - 1];
            a[x1][i - 1] = 0;
        }

        for (int i = x2; i < n - 1; i++) {
            a[i][0] = a[i + 1][0];
            a[i + 1][0] = 0;
        }
        for (int i = 0; i < m - 1; i++) {
            a[n - 1][i] = a[n - 1][i + 1];
            a[n - 1][i + 1] = 0;
        }
        for (int i = n - 1; i > x2; i--) {
            a[i][m - 1] = a[i - 1][m - 1];
            a[i - 1][m - 1] = 0;
        }
        for (int i = m - 1; i > 0; i--) {
            a[x2][i] = a[x2][i - 1];
            a[x2][i - 1] = 0;
        }
        a[x1][0] = -1;
        a[x2][0] = -1;
        a[x1][1] = 0;
        a[x2][1] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j];
        }
    }
    cout << ans + 2;
}
