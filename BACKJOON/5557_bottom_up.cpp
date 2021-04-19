#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[101];
ll d[101][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0][a[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0) {
                d[i][j] += d[i - 1][j - a[i]];
            }
            if (j + a[i] <= 20) {
                d[i][j] += d[i - 1][j + a[i]];
            }
        }
    }
    cout << d[n - 2][a[n - 1]];
}