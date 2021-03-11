#include <bits/stdc++.h>
using namespace std;

int a[4000001];
int b[4000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        auto iter = upper_bound(a, a + m, c);
        int idx = iter - a;
        if (b[idx] == 1) {
            for (int j = idx + 1; j <= m; j++) {
                if (b[j] == 0) {
                    idx = j;
                    break;
                }
            }
        }
        cout << a[idx] << '\n';
        b[idx] = 1;
    }
}