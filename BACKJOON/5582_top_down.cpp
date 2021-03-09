#include <bits/stdc++.h>
using namespace std;

int d[4001][4001];

string s1;
string s2;
int ans;
int foo(int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (d[i][j] != -1) return d[i][j];
    d[i][j] = 0;
    foo(i - 1, j);
    foo(i, j - 1);
    if (s1[i] == s2[j]) d[i][j] = foo(i - 1, j - 1) + 1;
    ans = max(ans, d[i][j]);
    return d[i][j];
}

int main() {
    memset(d, -1, sizeof(d));
    cin >> s1 >> s2;
    foo(s1.size() - 1, s2.size() - 1);
    cout << ans;
}