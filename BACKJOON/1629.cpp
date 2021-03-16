#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int foo(int a, int b) {
    if (b == 0) return 1;
    int tmp = foo(a, b / 2);
    if (b % 2 == 0) return 1ll * tmp * tmp % c;
    return 1ll * tmp * tmp % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << foo(a, b);
}