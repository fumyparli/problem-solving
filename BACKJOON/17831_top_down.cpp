#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<vector<int>> a(200001);
int c[200001];
int d[200001][2];

int foo(int x, int prev, int p) {
    if (a[x].size() == 0 && p == 0) return 0;
    int maxv = -inf;
    if (d[x][p] != -1) return d[x][p];
    d[x][p] = 0;
    for (auto &nx : a[x]) {
        int f0 = foo(nx, x, 0);
        int f1 = foo(nx, x, 1);
        d[x][p] += f0;
        maxv = max(maxv, f1 - f0);
    }
    if (p == 1) return d[x][p] + c[x] * c[prev];
    if (maxv > 0) d[x][p] += maxv;
    return d[x][p];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int k;
        cin >> k;
        a[k].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int cost;
        cin >> cost;
        c[i] = cost;
    }
    memset(d, -1, sizeof(d));
    cout << foo(1, 0, 0);
}