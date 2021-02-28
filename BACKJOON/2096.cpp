#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

int a[3];
int d[2][3];
int d2[2][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int ans2 = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                d[1][j] = max(d[0][j], d[0][j + 1]) + a[j];
            } else if (j == 1) {
                d[1][j] = max({d[0][j], d[0][j + 1], d[0][j - 1]}) + a[j];
            } else if (j == 2) {
                d[1][j] = max(d[0][j], d[0][j - 1]) + a[j];
            }
        }
        for (int j = 0; j < 3; j++) {
            d[0][j] = d[1][j];
        }
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                d2[1][j] = min(d2[0][j], d2[0][j + 1]) + a[j];
            } else if (j == 1) {
                d2[1][j] = min({d2[0][j], d2[0][j + 1], d2[0][j - 1]}) + a[j];
            } else if (j == 2) {
                d2[1][j] = min(d2[0][j], d2[0][j - 1]) + a[j];
            }
        }
        for (int j = 0; j < 3; j++) {
            d2[0][j] = d2[1][j];
        }
        ans = max({d[0][0], d[0][1], d[0][2]});
        ans2 = min({d2[0][0], d2[0][1], d2[0][2]});
    }
    cout << ans << " " << ans2;
}