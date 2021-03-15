#include <bits/stdc++.h>
using namespace std;

map<string, string> mss;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mss[s] = to_string(i + 1);
        mss[to_string(i + 1)] = s;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << mss[s] << '\n';
    }
}