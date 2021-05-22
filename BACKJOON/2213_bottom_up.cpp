#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(10001);
int cost[10001];
int d[10001][2];
vector<pair<int, int>> p[10001][2];

void foo(int x, int prev) {
    d[x][1] = cost[x];
    for (auto nx : a[x]) {
        if (prev == nx) continue;
        foo(nx, x);
        if (d[nx][0] < d[nx][1]) {
            d[x][0] += d[nx][1];
            p[x][0].push_back({nx, 1});
        } else {
            d[x][0] += d[nx][0];
            p[x][0].push_back({nx, 0});
        }
        d[x][1] += d[nx][0];
        p[x][1].push_back({nx, 0});
    }
    return;
}
set<int> ans;
void print(int x, int o) {
    if (o) ans.insert(x);
    for (auto nr : p[x][o]) {
        auto [nx, no] = nr;
        print(nx, no);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
        a[w].push_back(q);
    }
    foo(1, -1);
    if (d[1][0] < d[1][1]) {
        cout << d[1][1] << '\n';
        print(1, 1);
    } else {
        cout << d[1][0] << '\n';
        print(1, 0);
    }
    for (auto ans : ans) {
        cout << ans << " ";
    }
}