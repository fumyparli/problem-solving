#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans, a[26];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) a[s[j] - 'A'] += pow(10, (int)s.size() - j - 1);
    }
    sort(a, a + 26, greater<int>());
    cnt = 9;
    for (int i = 0; i < 26; i++) ans += a[i] * cnt--;
    cout << ans;
}