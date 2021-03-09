#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1000001);
int d[1000001][2];

void foo(int x, int prevx) {
    if (x != 1 && a[x].size() <= 1) {
        d[x][1] = 1;
        return;
    }
    d[x][1]++;
    for (auto& nx : a[x]) {
        if (nx == prevx) continue;
        foo(nx, x);
        d[x][1] += min(d[nx][0], d[nx][1]);
        d[x][0] += d[nx][1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
        a[w].push_back(q);
    }
    foo(1, 0);
    cout << min(d[1][0], d[1][1]);
}