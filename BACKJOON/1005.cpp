#include <bits/stdc++.h>
using namespace std;

int build_time[1001];
long long d[1001];
vector<vector<int>> a(1001);

long long foo(int x) {
    if (d[x] != -1) return d[x];
    d[x] = build_time[x];
    for (int i = 0; i < a[x].size(); i++) {
        int nx = a[x][i];
        d[x] = max(d[x], build_time[x] + foo(nx));
    }
    return d[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        for (auto& i : a) fill(i.begin(), i.end(), 0);
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> build_time[i];
        }
        for (int i = 0; i < k; i++) {
            int v, w;
            cin >> v >> w;
            a[w].push_back(v);
        }
        int st;
        cin >> st;
        cout << foo(st) << '\n';
    }
}