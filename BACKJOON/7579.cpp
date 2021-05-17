#include <bits/stdc++.h>
using namespace std;

int a[101];
int c[101];
int d[101][10001];

// d[i][j] = i까지 사용해서 들인비용이 j일때 얻을 수 있는 최대 바이트

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    d[0][c[0]] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10001; j++) {
            d[i][j] = max(d[i][j], d[i - 1][j]);
            if (j + c[i] <= 10000)
                d[i][j + c[i]] = max(d[i][j + c[i]], d[i - 1][j] + a[i]);
        }
    }
    int ans = 2'000'000'000;
    for (int j = 0; j < 10001; j++) {
        if (d[n - 1][j] >= m) {
            ans = min(ans, j);
        }
    }
    cout << ans;
}