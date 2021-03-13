#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> a(10001);
int check[10001];

pair<int, int> foo(int st, int x, int level) {
    check[x] = 1;
    if (a[x].size() <= 1 && x != st) {
        return {x, level};
    }
    int maxv = -1;
    int maxi = -1;
    for (auto &nx : a[x]) {
        if (check[nx.first] == 1) continue;
        pair<int, int> tmp = foo(x, nx.first, level + nx.second);
        if (maxv < tmp.second) {
            maxv = tmp.second;
            maxi = tmp.first;
        }
    }
    return {maxi, maxv};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        a[q].push_back({w, e});
        a[w].push_back({q, e});
    }
    pair<int, int> tmp = foo(1, 1, 0);
    if (tmp.first == -1) {
        cout << 0;
        return 0;
    }
    memset(check, 0, sizeof(check));
    cout << foo(tmp.first, tmp.first, 0).second;
}