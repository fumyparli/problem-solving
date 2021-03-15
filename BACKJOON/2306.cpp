#include <bits/stdc++.h>
using namespace std;

string s;
int d[501][501];

int foo(int i, int j) {
    if (i >= j) return 0;
    if (d[i][j] != -1) return d[i][j];
    int tmp = 0, tmp2 = 0;
    for (int k = i; k < j; k++) {
        tmp = max(tmp, (foo(i, k) + foo(k + 1, j)));
    }
    if ((s[i] == 'a' && s[j] == 't') || (s[i] == 'g' && s[j] == 'c')) {
        tmp2 = foo(i + 1, j - 1) + 2;
    }
    d[i][j] = max(tmp, tmp2);
    return d[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    memset(d, -1, sizeof(d));
    cout << foo(0, s.size() - 1);
}