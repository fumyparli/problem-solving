#include <bits/stdc++.h>
using namespace std;

unordered_set<string> se;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        se.insert(s);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (se.find(s) != se.end()) ans++;
    }
    cout << ans;
}