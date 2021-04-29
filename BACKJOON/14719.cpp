#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int check[501][501];
int n, m;
void gol(int x, int y, int &cnt) {
    if (y == 0) {
        if (a[x][y] == 0) cnt = -1;
        return;
    }
    if (a[x][y] == 1) return;
    cnt++;
    check[x][y] = 1;
    gol(x, y - 1, cnt);
}
void gor(int x, int y, int &cnt) {
    if (y == m - 1) {
        if (a[x][y] == 0) cnt = -1;
        return;
    }
    if (a[x][y] == 1) return;
    cnt++;
    check[x][y] = 1;
    gor(x, y + 1, cnt);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            a[j][i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] == 0 && check[i][j] == 0) {
                int cnt = 0, cnt2 = 0;
                gol(i, j - 1, cnt);
                if (cnt == -1) continue;
                gor(i, j + 1, cnt2);
                if (cnt2 == -1) continue;
                ans += cnt + cnt2 + 1;
            }
        }
    }
    cout << ans;
}