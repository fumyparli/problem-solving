#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vvll vector<vector<ll>>
vvll a = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};
vvll get_m(vvll m1, vvll m2) {
    vvll tmp(8, vector<ll>(8));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                tmp[i][j] = (tmp[i][j] + m1[i][k] % mod * m2[k][j]) % mod;
    return tmp;
}

vvll foo(int n) {
    if (n == 1) return a;
    vvll tmp = foo(n / 2);
    if (n % 2 == 0)
        return get_m(tmp, tmp);
    else
        return get_m(get_m(tmp, tmp), a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << foo(n)[0][0];
}