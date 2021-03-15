#include <bits/stdc++.h>
using namespace std;

int d[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            for (int k = i; k < i + j; k++) {
                d[i][i + j] = max(d[i][i + j], d[i][k] + d[k + 1][i + j]);
                if ((s[i] == 'a' && s[i + j] == 't') || (s[i] == 'g' && s[i + j] == 'c')) {
                    d[i][i + j] = max(d[i][i + j], d[i + 1][i + j - 1] + 2);
                }
            }
        }
    }
    cout << d[0][n - 1];
}