#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int st = 1, ed = 1'000'000'000;
    while (true) {
        if (st >= ed) break;
        int mid = (st + ed) / 2;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += min(mid / i, n);
        }
        if (sum >= k) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    cout << ed;
}