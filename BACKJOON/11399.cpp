#include <bits/stdc++.h>
using namespace std;

int d[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d + n);
    for (int i = 1; i < n; i++) {
        d[i] += d[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i];
    }
    cout << ans;
}