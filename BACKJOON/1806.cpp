#include <bits/stdc++.h>
using namespace std;
#define inf 100001
int a[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0, ed = 0;
    long long sum = 0;
    int ans = inf;
    while (ed <= n) {
        if (sum >= s) {
            ans = min(ans, ed - st);
            sum -= a[st++];
        } else {
            sum += a[ed++];
        }
    }
    if (ans == inf) {
        cout << 0;
        return 0;
    }
    cout << ans;
}