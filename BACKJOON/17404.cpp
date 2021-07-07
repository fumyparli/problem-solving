#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][3];
int d[1001][3];
#define INF 123456789;
int foo(int x, int y, int z) {
    d[1][x] = INF;
    d[1][y] = a[0][x] + a[1][y];
    d[1][z] = a[0][x] + a[1][z];
    for (int i = 2; i < n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
    }
    return min(d[n - 1][y], d[n - 1][z]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INF;
    ans = min(ans, foo(0, 1, 2));
    memset(d, 0, sizeof(d));
    ans = min(ans, foo(1, 0, 2));
    memset(d, 0, sizeof(d));
    ans = min(ans, foo(2, 0, 1));
    cout << ans;
}