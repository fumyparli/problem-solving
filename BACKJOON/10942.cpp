#include <bits/stdc++.h>
using namespace std;

int d[2001][2001];
int a[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            d[i][i + 1] = 1;
        }
    }

    for (int i = n - 2; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] == a[j + n - i] && d[j + 1][j + n - i - 1]) {
                d[j][j + n - i] = 1;
            }
        }
    }

    int m;
    cin >> m;
    for (int t = 0; t < m; t++) {
        int s, e;
        cin >> s >> e;
        cout << d[s - 1][e - 1] << '\n';
    }
}