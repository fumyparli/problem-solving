#include <bits/stdc++.h>
using namespace std;

vector<int> get_pi(string p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        auto v = get_pi(s.substr(i));
        ans = max(ans, *max_element(v.begin(), v.end()));
    }
    cout << ans;
}