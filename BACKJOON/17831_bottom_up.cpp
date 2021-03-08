#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<vector<int>> a(200001);
int c[200001];
int d[200001][2];

void foo(int x, int prev) {
    int maxv = -inf;
    for (int i = 0; i < a[x].size(); i++) {
        int nx = a[x][i];
        foo(nx, x);
        d[x][1] += d[nx][0];
        d[x][0] += d[nx][0];
        if (maxv < d[nx][1] - d[nx][0]) {
            maxv = d[nx][1] - d[nx][0];
        }
    }
    d[x][1] += c[x] * c[prev];
    if (maxv > 0) {
        d[x][0] += maxv;
    }
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
    foo(1, 0);
    cout << max(d[1][0], d[1][1]);
}