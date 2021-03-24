#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define ll long long
#define inf 9'000'000'000'000'000'000
ll d[100001];
vvpll a(100001);
priority_queue<pll, vpll, greater<pll>> pq;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        a[w].push_back({e, q});
    }
    for (int i = 1; i <= n; i++) d[i] = inf;
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        pq.push({0, q});
        d[q] = 0;
    }
    while (!pq.empty()) {
        int x = pq.top().second;
        ll tc = pq.top().first;
        pq.pop();
        if (d[x] < tc) continue;
        for (auto &nr : a[x]) {
            int nx = nr.second;
            int nc = nr.first;
            if (d[x] + nc < d[nx]) {
                d[nx] = d[x] + nc;
                pq.push({d[nx], nx});
            }
        }
    }
    ll maxv = -1, maxi = -1;
    for (ll i = 1; i <= n; i++) {
        if (maxv == d[i])
            maxi = min(maxi, i);
        else if (d[i] != inf && maxv < d[i]) {
            maxv = d[i];
            maxi = i;
        }
    }
    cout << maxi << '\n'
         << maxv;
}