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

int kmp(string s, string p) {
    vector<int> pi = get_pi(p);
    int n = s.size();
    int m = p.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                return i - j;
            } else {
                j++;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string s;
        cin >> s;
        if (s == ".") break;
        auto tmp = get_pi(s);
        string pi = "";
        for (auto& i : tmp) pi += i + '0';
        if (tmp.back() == 0) {
            cout << 1 << '\n';
            continue;
        }
        string k = "";
        for (int i = 1; i <= tmp.back(); i++) k += i + '0';
        int st = kmp(pi, k);
        if (st == -1 || s.size() % st != 0) {
            cout << 1 << '\n';
            continue;
        }
        cout << s.size() / st << '\n';
    }
}