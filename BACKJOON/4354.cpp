#include <bits/stdc++.h>
using namespace std;

vector<int> get_pi(string p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string s;
        cin >> s;
        if (s == ".") break;
        auto pi = get_pi(s);
        int n = s.size();
        int ed = pi.back();
        if (n % (n - ed) == 0)
            cout << n / (n - ed) << '\n';
        else
            cout << 1 << '\n';
    }
}