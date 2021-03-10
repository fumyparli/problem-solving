#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
long long d[101][10][1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++) {
        d[1][i][1 << i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j - 1 >= 0) {
                    d[i][j][k | (1 << j)] += d[i - 1][j - 1][k];
                    d[i][j][k | (1 << j)] %= inf;
                }
                if (j + 1 < 10) {
                    d[i][j][k | (1 << j)] += d[i - 1][j + 1][k];
                    d[i][j][k | (1 << j)] %= inf;
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < 10; j++) {
        ans += d[n][j][1023];
        ans %= inf;
    }
    cout << ans;
}