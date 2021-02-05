#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int foo(int i, int j) {
    if (i == j || j == 0) return 1;
    if (d[i][j] != -1) return d[i][j];
    return d[i][j] = (foo(i - 1, j - 1) + foo(i - 1, j)) % 10007;
}

int main() {
    memset(d, -1, sizeof(d));
    int n, k;
    cin >> n >> k;
    cout << foo(n, k);
}