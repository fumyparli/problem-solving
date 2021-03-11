#include <bits/stdc++.h>
using namespace std;

int a[19][19];
int b[19][19];
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};
int n;

void convert(int i, int j) {
    for (int k = 0; k < 5; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            a[nx][ny] = !a[nx][ny];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    int ans = 10000;
    for (int k = 0; k < (1 << n); k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = b[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (k & (1 << i)) {
                convert(0, i);
                cnt++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i - 1][j] == 1) {
                    cnt++;
                    convert(i, j);
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            ans = min(ans, cnt);
        }
    }
    if (ans == 10000) {
        cout << -1;
        return 0;
    }
    cout << ans;
}