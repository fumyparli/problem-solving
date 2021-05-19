#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define inf 2'000'000'000
vector<vector<pii>> a(501);
vector<vector<int>> p(501);
priority_queue<pii, vector<pii>, greater<pii>> pq;
int d[501];
int check[501][501];
int n, m;

void dijk(int st, int ed, int o) {
    for (int i = 0; i < n; i++) d[i] = inf;
    d[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        auto [c, x] = pq.top();
        pq.pop();
        if (d[x] < c) continue;
        for (auto nr : a[x]) {
            auto [nc, nx] = nr;
            if (o == 0) {
                if (d[nx] > d[x] + nc) {
                    d[nx] = d[x] + nc;
                    pq.push({d[nx], nx});
                    p[nx].clear();
                }
                if (d[nx] >= d[x] + nc) p[nx].push_back(x);
            } else {
                if (check[x][nx] == 0 && d[nx] > d[x] + nc) {
                    d[nx] = d[x] + nc;
                    pq.push({d[nx], nx});
                }
            }
        }
    }
}

void eraseShtPath(int x) {
    for (auto px : p[x]) {
        if (check[px][x] == 0) {
            check[px][x] = 1;
            eraseShtPath(px);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        memset(check, 0, sizeof(check));
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            a[i].clear();
            p[i].clear();
        }
        int st, ed;
        cin >> st >> ed;
        for (int i = 0; i < m; i++) {
            int q, w, e;
            cin >> q >> w >> e;
            a[q].push_back({e, w});
        }
        dijk(st, ed, 0);
        eraseShtPath(ed);
        dijk(st, ed, 1);
        if (d[ed] == inf)
            cout << -1 << '\n';
        else
            cout << d[ed] << '\n';
    }
}