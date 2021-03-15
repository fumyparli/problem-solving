#include <bits/stdc++.h>
using namespace std;

int t;
int a[11][11];
int d[11][1024];

bool check_possible(int k1, int k2, int m) {
    int flag = 0;
    for (int i = 0; i < m; i++) {
        if (k2 & (1 << i)) {
            if (i - 1 >= 0 && !((k1 & (1 << (i - 1))) == 0 && (k2 & (1 << (i - 1))) == 0)) {
                flag = 1;
                break;
            }
            if (i + 1 < m && !((k1 & (1 << (i + 1))) == 0 && (k2 & (1 << (i + 1))) == 0)) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) return 1;
    return 0;
}

int count_bits(int k, int n, int m) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if ((k & (1 << i)) && a[n][i] == 1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '.')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
        int ans = 0;
        for (int k1 = 0; k1 < (1 << m); k1++) {
            if (check_possible(0, k1, m))
                d[0][k1] = count_bits(k1, 0, m);
        }
        for (int i = 1; i < n; i++) {
            for (int k1 = 0; k1 < (1 << m); k1++) {
                for (int k2 = 0; k2 < (1 << m); k2++) {
                    if (check_possible(k1, k2, m)) {
                        d[i][k2] = max(d[i][k2], d[i - 1][k1] + count_bits(k2, i, m));
                    }
                }
            }
        }
        for (int k2 = 0; k2 < (1 << m); k2++) {
            ans = max(ans, d[n - 1][k2]);
        }
        cout << ans << '\n';
    }
}