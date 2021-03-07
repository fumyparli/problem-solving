#include <bits/stdc++.h>
using namespace std;

int a[10001];
int d[10001][2];
vector<vector<int>> v(10001);

int foo(int x, int prev, int p) {
    if (d[x][p]) return d[x][p];
    if (p == 1) d[x][p] = a[x];
    for (int i = 0; i < v[x].size(); i++) {
        int nx = v[x][i];
        if (nx == prev)
            continue;
        if (p == 0) {
            d[x][0] += max(foo(nx, x, 0), foo(nx, x, 1));
        } else {
            d[x][1] += foo(nx, x, 0);
        }
    }
    return d[x][p];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int q, w;
        cin >> q >> w;
        v[q].push_back(w);
        v[w].push_back(q);
    }
    cout << max(foo(1, 0, 0), foo(1, 0, 1));
}