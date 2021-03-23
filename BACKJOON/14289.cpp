#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
vvll a(50, vll(50));
vvll get_m(vvll m1, vvll m2) {
    vvll tmp(50, vector<ll>(50));
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 50; k++)
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
    int n, m, d;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w;
        cin >> q >> w;
        a[q - 1][w - 1] = 1;
        a[w - 1][q - 1] = 1;
    }
    cin >> d;
    cout << foo(d)[0][0];
}