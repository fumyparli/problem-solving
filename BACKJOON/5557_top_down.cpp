#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[101];
ll d[101][21];
int n;

ll foo(int i, int sum) {
    if (i == n - 2) {
        if (sum == a[n - 1]) return 1;
        return 0;
    }
    if (d[i][sum] != -1) {
        return d[i][sum];
    }
    d[i][sum] = 0;
    if (sum - a[i + 1] >= 0) {
        d[i][sum] += foo(i + 1, sum - a[i + 1]);
    }
    if (sum + a[i + 1] <= 20) {
        d[i][sum] += foo(i + 1, sum + a[i + 1]);
    }
    return d[i][sum];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    cout << foo(0, a[0]);
}