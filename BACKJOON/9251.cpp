#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int d[1001][1001];

int foo(int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (d[i][j] != -1) return d[i][j];
    int tmp = -1;
    if (s1[i] == s2[j])
        d[i][j] = foo(i - 1, j - 1) + 1;
    else
        d[i][j] = max(foo(i - 1, j), foo(i, j - 1));
    return d[i][j];
}

int main() {
    memset(d, -1, sizeof(d));
    cin >> s1 >> s2;
    cout << foo(s1.size() - 1, s2.size() - 1);
}