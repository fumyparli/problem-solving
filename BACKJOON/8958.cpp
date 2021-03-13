#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += cnt;
        }
        cout << ans << '\n';
    }
}