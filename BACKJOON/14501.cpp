#include <bits/stdc++.h>
using namespace std;

int t[16];
int p[16];
int d[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (i + t[i] <= n) {
            d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
        }
        d[i + 1] = max(d[i + 1], d[i]);
    }
    for (int i = 0; i <= n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    cout << ans;
}