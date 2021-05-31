#include <bits/stdc++.h>
using namespace std;
#define inf 2'000'000'000
vector<vector<pair<int, int>>> a(1001);
int d[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 1000; i++) {
        d[i] = inf;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        a[q].push_back({w, e});
    }
    int st, ed;
    cin >> st >> ed;
    d[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto nr : a[x]) {
            auto [nx, nc] = nr;
            if (d[nx] > d[x] + nc) {
                d[nx] = d[x] + nc;
                q.push(nx);
            }
        }
    }
    cout << d[ed];
}