#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
string ans;
string s1, s2;

void foo(int i, int j) {
    if (i == 0 || j == 0) return;
    if (s1[i] == s2[j]) {
        foo(i - 1, j - 1);
        cout << s1[i];
    } else {
        if (d[i - 1][j] < d[i][j - 1]) {
            foo(i, j - 1);
        } else {
            foo(i - 1, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
            }
        }
    }
    cout << d[s1.size() - 1][s2.size() - 1] << '\n';
    foo(s1.size() - 1, s2.size() - 1);
}