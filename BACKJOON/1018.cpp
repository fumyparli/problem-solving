#include <bits/stdc++.h>
using namespace std;

int cnt;
int a[51][51];

void check_chess(const int &i, const int &j, int k) {
    cnt = 0;
    for (int q = i; q < i + 8; q++) {
        for (int w = j; w < j + 8; w++) {
            if (a[q][w] != (q % 2 + w % 2 + k) % 2)
                cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'B')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    int ans = 2000000000;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            check_chess(i, j, 0);
            ans = min(ans, cnt);
            check_chess(i, j, 1);
            ans = min(ans, cnt);
        }
    }
    cout << ans;
}