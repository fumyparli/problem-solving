#include <bits/stdc++.h>
using namespace std;

int a[501];
int d[501][501];
int s[501];

int foo(int i, int j) {
    if (i == j) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    for (int k = i; k <= j - 1; k++) {
        int tmp = foo(i, k) + foo(k + 1, j) + s[j] - s[i - 1];
        if (d[i][j] == -1 || tmp < d[i][j]) {
            d[i][j] = tmp;
        }
    }
    return d[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        cout << foo(1, n) << '\n';
    }
}