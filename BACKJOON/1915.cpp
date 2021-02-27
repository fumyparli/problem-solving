#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            d[i][j + 1] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] != 0) {
                d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
                if (ans < d[i][j]) ans = d[i][j];
            }
        }
    }
    cout << ans * ans;
}