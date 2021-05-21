#include <bits/stdc++.h>
using namespace std;

int lmax[501];
int rmax[501];
int a[501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    lmax[0] = a[0];
    rmax[m - 1] = a[m - 1];
    for (int i = 1; i < m - 1; i++) {
        lmax[i] = max(lmax[i - 1], a[i]);
        rmax[m - i - 1] = max(rmax[m - i], a[m - i - 1]);
    }
    for (int i = 0; i < m; i++) {
        int toadd = max(min(lmax[i], rmax[i]) - a[i], 0);
        ans += toadd;
    }
    cout << ans;
}