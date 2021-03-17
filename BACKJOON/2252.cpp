#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a(32001);
vector<int> v;
int check[32001];

void foo(int x) {
    check[x] = 1;
    for (auto& nx : a[x]) {
        if (check[nx] == 0) {
            foo(nx);
        }
    }
    v.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            foo(i);
        }
    }
    reverse(v.begin(), v.end());
    for (auto& i : v) {
        cout << i << " ";
    }
}