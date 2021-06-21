#include <bits/stdc++.h>
using namespace std;

int a[51][51];
int n, m, t;
int check[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int flag;

void rotate(int i, int d, int k) {
    while (k--) {
        if (d == 0) {
            int tmp = a[i][m - 1];
            for (int j = m - 1; j >= 0; j--) {
                if (j == 0) {
                    a[i][j] = tmp;
                } else {
                    a[i][j] = a[i][j - 1];
                }
            }
        }
        if (d == 1) {
            int tmp = a[i][0];
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    a[i][j] = tmp;
                } else {
                    a[i][j] = a[i][j + 1];
                }
            }
        }
    }
}

void dfs(int x, int y, int aa) {
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = (y + dy[k] + m) % m;
        if (0 <= nx && 0 <= ny && nx < n && ny < m) {
            if (check[nx][ny] == 0) {
                if (aa != a[nx][ny]) {
                    continue;
                }
                dfs(nx, ny, a[nx][ny]);
                a[x][y] = 0;
                a[nx][ny] = 0;
                flag = 1;
            }
        }
    }
}
void aver(int sum, int cnt) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sum < a[i][j] * cnt) {
                a[i][j]--;
            } else if (sum > a[i][j] * cnt && a[i][j] != 0) {
                a[i][j]++;
            }
        }
    }
}

void foo(int x, int d, int k) {
    memset(check, 0, sizeof(check));
    int sum2 = 0;
    int cnt2 = 0;
    for (int i = x; i <= n; i += x) {
        rotate(i - 1, d, k);
    }
    flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                sum2 += a[i][j];
                cnt2++;
                dfs(i, j, a[i][j]);
            }
        }
    }
    if (flag == 0) {
        aver(sum2, cnt2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < t; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        foo(x, d, k);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }
    cout << sum;
}