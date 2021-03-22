#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

int d[10001][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> a(2);
        int n, w;
        cin >> n >> w;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                int k;
                cin >> k;
                a[i].push_back(k);
            }
        }
        int ans = inf;
        for (int l = 0; l < 4; l++) {
            for (int i = 0; i < 10001; i++) {
                for (int j = 0; j < 5; j++) {
                    d[i][j] = inf;
                }
            }
            if (l == 0) {
                if (a[0][0] + a[0][n - 1] > w) continue;
                d[0][1] = 2;
                d[0][3] = 1;
            } else if (l == 1) {
                if (a[1][0] + a[1][n - 1] > w) continue;
                d[0][1] = 2;
                d[0][2] = 1;
            } else if (l == 2) {
                if (a[0][0] + a[1][0] <= w) d[0][0] = 1;
                d[0][1] = 2;
                d[0][2] = 1;
                d[0][3] = 1;
                d[0][4] = 0;
            } else if (l == 3) {
                if (a[0][0] + a[0][n - 1] > w || a[1][0] + a[1][n - 1] > w) continue;
                d[0][1] = 2;
            }
            for (int i = 1; i < n; i++) {
                if (a[0][i] + a[1][i] <= w)
                    d[i][0] = min(d[i - 1][0], d[i - 1][1]) + 1;
                if (a[0][i] + a[0][i - 1] <= w)
                    d[i][1] = min(d[i][1], d[i - 1][2] + 2);
                if (a[1][i] + a[1][i - 1] <= w)
                    d[i][1] = min(d[i][1], d[i - 1][3] + 2);
                if (a[0][i] + a[0][i - 1] <= w && a[1][i] + a[1][i - 1] <= w)
                    d[i][1] = min(d[i][1], d[i - 1][4] + 2);
                d[i][1] = min({d[i][1], d[i - 1][0] + 2, d[i - 1][1] + 2});
                if (a[1][i] + a[1][i - 1] <= w)
                    d[i][2] = min(d[i][2], d[i - 1][3] + 1);
                d[i][2] = min({d[i][2], d[i - 1][0] + 1, d[i - 1][1] + 1});
                if (a[0][i] + a[0][i - 1] <= w)
                    d[i][3] = min(d[i][3], d[i - 1][2] + 1);
                d[i][3] = min({d[i][3], d[i - 1][0] + 1, d[i - 1][1] + 1});
                d[i][4] = min(d[i - 1][0], d[i - 1][1]);
            }
            int minv = inf;
            if (l == 0) {
                minv = min(minv, d[n - 1][2]);
            } else if (l == 1) {
                minv = min(minv, d[n - 1][3]);
            } else if (l == 2) {
                minv = min({minv, d[n - 1][0], d[n - 1][1]});
            } else if (l == 3) {
                minv = min(minv, d[n - 1][4]);
            }
            for (int i = 0; i < 2; i++)
                minv = min(minv, d[n - 1][i]);
            ans = min(ans, minv);
        }
        cout << ans << '\n';
    }
}