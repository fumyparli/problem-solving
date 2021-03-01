#include <bits/stdc++.h>
using namespace std;

int d[1001];

int foo(int i, int turn) {
    if (i < 0) return 1;
    if (i == 0) return turn;
    if (d[i] != -1) return d[i];
    return d[i] = (foo(i - 1, !turn) && foo(i - 3, !turn));
}

int main() {
    int n;
    cin >> n;
    memset(d, -1, sizeof(d));
    if (foo(n, 1) == 0) {
        cout << "SK";
    } else {
        cout << "CY";
    }
}