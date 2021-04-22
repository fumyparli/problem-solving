#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int get_gcd(int x, int y) {
    while (true) {
        if (x == y) return x;
        if (x > y) swap(x, y);
        y = y - x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(abs(k - s));
    }
    int ans = a[0];
    for (int i = 1; i < a.size(); i++) {
        ans = min(ans, get_gcd(a[i], a[i - 1]));
    }
    cout << ans;
}