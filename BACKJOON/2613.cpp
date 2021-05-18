#include <bits/stdc++.h>
using namespace std;

int a[301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int st = 0, ed = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st = max(st, a[i]);
        ed += a[i];
    }
    while (st < ed) {
        int mid = (st + ed) / 2;
        int cnt = 1, total = 0;
        for (int i = 0; i < n; i++) {
            total += a[i];
            if (total > mid) {
                cnt++;
                total = a[i];
            }
        }
        if (cnt <= m) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    cout << ed << '\n';
    int total = 0, cnt = 0, mergecnt = 0, i = 0;
    for (i = 0; i <= n; i++) {
        if (total + a[i] > ed || i == n) {
            cout << cnt << " ";
            total = a[i];
            cnt = 1;
            mergecnt++;
        } else {
            total += a[i];
            cnt++;
        }
        if (n - i + mergecnt < m) {
            break;
        }
    }
    i -= cnt - 1;
    for (; i < n; i++) {
        cout << 1 << " ";
    }
}