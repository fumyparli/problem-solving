#include <bits/stdc++.h>
using namespace std;

int d[1000001];

int foo(int i) {
    if (i == 0) {
        return 1;
    }
    if (i == 1) {
        return 1;
    }
    if (d[i] != -1) {
        return d[i];
    }
    return d[i] = (foo(i - 1) + foo(i - 2)) % 15746;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(d, -1, sizeof(d));
    d[0] = 1;
    d[1] = 1;
    int n;
    cin >> n;
    cout << foo(n);
}