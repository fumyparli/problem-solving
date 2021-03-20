#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

int d[10011][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> a(2, vector<int>(10001));
        int n, w;
        cin >> n >> w;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a[0][i] = k;
        }
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a[1][i] = k;
        }
        a[0].push_back(a[0][0]);
        a[1].push_back(a[1][0]);
        a[0].push_back(a[0][1]);
        a[1].push_back(a[1][1]);
        int ans = inf;
        for (int l = 0; l < 3; l++) {
            for (int i = 0; i < 10011; i++) {
                for (int j = 0; j < 5; j++) {
                    d[i][j] = inf;
                }
            }
            if (a[0][l] + a[1][l] <= w) d[l][0] = 1;
            d[l][1] = 2;
            d[l][2] = 1;
            d[l][3] = 1;
            d[l][4] = 0;
            for (int i = 1 + l; i < n + l; i++) {
                if (a[0][i] + a[1][i] <= w) {
                    d[i][0] = min(d[i - 1][0], d[i - 1][1]) + 1;
                }
                if (a[0][i] + a[0][i - 1] <= w) {
                    d[i][1] = min(d[i][1], d[i - 1][2] + 2);
                }
                if (a[1][i] + a[1][i - 1] <= w) {
                    d[i][1] = min(d[i][1], d[i - 1][3] + 2);
                }
                if (a[0][i] + a[0][i - 1] <= w && a[1][i] + a[1][i - 1] <= w) {
                    d[i][1] = min(d[i][1], d[i - 1][4] + 2);
                }
                d[i][1] = min({d[i][1], d[i - 1][0] + 2, d[i - 1][1] + 2});
                if (a[1][i] + a[1][i - 1] <= w) {
                    d[i][2] = min(d[i][2], d[i - 1][3] + 1);
                }
                d[i][2] = min({d[i][2], d[i - 1][0] + 1, d[i - 1][1] + 1});
                if (a[0][i] + a[0][i - 1] <= w) {
                    d[i][3] = min(d[i][3], d[i - 1][2] + 1);
                }
                d[i][3] = min({d[i][3], d[i - 1][0] + 1, d[i - 1][1] + 1});
                d[i][4] = min(d[i - 1][0], d[i - 1][1]);
            }
            int minv = inf;
            for (int i = 0; i < 5; i++) {
                minv = min(minv, d[n - 1 + l][i]);
            }
            cout << "l: " << l << '\n';
            for (int k = 0; k < 5; k++) {
                for (int i = l; i < n + l; i++) {
                    if (d[i][k] == inf)
                        cout << "f"
                             << " ";
                    else
                        cout << d[i][k] << " ";
                }
                cout << '\n';
            }
            ans = min(ans, minv);
        }
        cout << ans << '\n';
    }
}