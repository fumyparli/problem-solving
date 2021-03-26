#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define inf 2000000000
int d[20001];
vvpii a(20001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, st;
    cin >> n >> m >> st;
    for (int i = 0; i < m; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        a[q].push_back({e, w});
    }
    for (int i = 1; i <= n; i++) d[i] = inf;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, st});
    d[st] = 0;
    while (!pq.empty()) {
        int x = pq.top().second;
        int tc = pq.top().first;
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
    for (int i = 1; i <= n; i++) {
        if (d[i] == inf)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
}