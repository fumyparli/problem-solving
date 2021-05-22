#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(10001);
int cost[10001];
int d[10001][2];

int foo(int x, int o, int p) {
    if (d[x][o]) return d[x][o];
    if (o) d[x][o] = cost[x];
    for (auto nx : a[x]) {
        if (nx == p) continue;
        if (o)
            d[x][o] += foo(nx, 0, x);
        else {
            d[x][o] += max(foo(nx, 0, x), foo(nx, 1, x));
        }
    }
    return d[x][o];
}

set<int> ans;
void print(int x, int o, int p) {
    if (o) ans.insert(x);
    for (auto nx : a[x]) {
        if (p == nx) continue;
        if (o) {
            print(nx, 0, x);
        } else {
            if (d[nx][0] < d[nx][1])
                print(nx, 1, x);
            else
                print(nx, 0, x);
        }
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
    foo(1, 0, -1);
    foo(1, 1, -1);
    if (d[1][0] < d[1][1]) {
        cout << d[1][1] << '\n';
        print(1, 1, -1);
    } else {
        cout << d[1][0] << '\n';
        print(1, 0, -1);
    }
    for (auto ans : ans) {
        cout << ans << " ";
    }
}