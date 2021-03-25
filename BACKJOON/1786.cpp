#include <bits/stdc++.h>
using namespace std;
vector<int> get_pi(string p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}
vector<int> kmp(string s, string p) {
    vector<int> pi = get_pi(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int i = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, p;
    getline(cin, s, '\n');
    getline(cin, p, '\n');
    vector<int> ans = kmp(s, p);
    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i + 1 << " ";
}