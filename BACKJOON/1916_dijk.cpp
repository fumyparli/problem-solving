#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
#define inf 2'000'000'000
vvpii a(1001);
int d[1001];
int check[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 1001; i++) {
        d[i] = inf;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        a[q].push_back({e, w});
    }
    int st, ed;
    cin >> st >> ed;
    priority_queue<pii, vpii, greater<pii>> pq;
    d[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        auto [c, x] = pq.top();
        pq.pop();
        if (c > d[x]) continue;
        for (auto ne : a[x]) {
            auto [nc, nx] = ne;
            if (d[nx] > d[x] + nc) {
                d[nx] = d[x] + nc;
                pq.push({d[nx], nx});
            }
        }
    }
    cout << d[ed];
}