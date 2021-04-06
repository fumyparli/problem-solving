#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a;
vector<pair<ll, ll>> b;
vector<ll> d(90001);

ll solution(vector<vector<int>> land, int p, int q) {
    int n = land.size();
    ll nn = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.push_back(land[i][j]);
        }
    }
    sort(a.begin(), a.end());
    b.push_back({0, 0});
    for (auto &r : a) {
        if (b.back().first == r) {
            b.back().second++;
        } else {
            b.push_back({r, 1});
        }
    }
    for (int i = 1; i < b.size(); i++) {
        b[i].second += b[i - 1].second;
    }
    for (int i = 1; i < b.size(); i++) {
        d[i] = d[i - 1] + (nn - b[i - 1].second) * (b[i].first - b[i - 1].first);
    }
    ll total = d[(int)b.size() - 1];
    ll ans = 9'000'000'000'000'000'000;
    for (int i = 0; i < b.size(); i++) {
        ll tofill = nn * b[i].first - d[i];
        ll todelete = total - d[i];
        ans = min(ans, p * tofill + q * todelete);
    }
    return ans;
}