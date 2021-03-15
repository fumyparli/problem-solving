#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int tmp = n / h;
        if (n % h == 0) {
            cout << h;
        } else {
            cout << n % h;
            tmp++;
        }
        if (tmp < 10) cout << 0;
        cout << tmp << '\n';
    }
}