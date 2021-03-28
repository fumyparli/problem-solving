#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll = long long;

vector<pair<ll, ll>> v;

ll get_rn(ll r, ll n) {
    if (n == 0) return 1;
    ll tmp = get_rn(r, n / 2);
    ll ret;
    if (n % 2 == 0)
        ret = ((tmp % mod) * (tmp % mod)) % mod;
    else
        ret = ((((tmp % mod) * (tmp % mod)) % mod) * (r % mod)) % mod;
    return ret;
}

void get_prime_factor(int n) {
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (v.empty() || v.back().first != i)
                v.push_back({i, 1});
            else
                v.back().second++;
            n /= i;
        }
    }
    if (n > 1) {
        v.push_back({n, 1});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll rr, nn;
    cin >> rr >> nn;
    if (rr == 1) {
        cout << 1;
        return 0;
    }
    get_prime_factor(rr);
    ll ans = 1;
    for (auto& x : v) {
        auto [r, n] = x;
        n *= nn;
        n++;
        if (r == 1) continue;
        n = get_rn(r, n) - 1;
        r = get_rn(r - 1, mod - 2);
        ll tmp = (n * r) % mod;
        ans = (ans * tmp) % mod;
    }
    cout << ans;
}