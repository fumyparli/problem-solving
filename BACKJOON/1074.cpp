#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    int m = (1 << n) * (1 << n);
    int x1 = 0, y1 = 0, x2 = (1 << n) - 1, y2 = (1 << n) - 1;
    int ans = 0;
    while (true) {
        if (x1 == x2 && y1 == y2) break;
        int k = 0;
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;
        if (midx + 1 <= r && r <= x2) {
            k += 2;
            x1 = midx + 1;
        } else {
            x2 = midx;
        }
        if (midy + 1 <= c && c <= y2) {
            k++;
            y1 = midy + 1;
        } else {
            y2 = midy;
        }
        m /= 4;
        ans += m * k;
    }
    cout << ans;
}