#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<vector<int>> a(200001);
int c[200001];
int d[200001][2];

void foo(int x) {
    if (a[x].size() == 0) return;
    for (auto& nx : a[x]) {
        foo(nx);
        d[x][0] += max(d[nx][0], d[nx][1]);
        d[x][1] += max(d[nx][0], d[nx][1]);
    }
    int maxv = -inf;
    for (auto& nx : a[x]) {
        int tmpv = d[nx][0] - d[nx][1];
        if (tmpv > 0) tmpv = 0;
        maxv = max(maxv, c[x] * c[nx] + tmpv);
    }
    d[x][1] += maxv;
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
    foo(1);
    cout << max(d[1][0], d[1][1]);
}