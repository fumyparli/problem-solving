#include <bits/stdc++.h>
using namespace std;

vector<string> a;

bool cmp(const string& s1, const string& s2) {
    if (s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto& i : a) {
        cout << i << '\n';
    }
}