#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(10001);
vector<vector<int>> ra(10001);
vector<vector<int>> ans(10001);
int check[10001];

void foo(int x, vector<int>& v, vector<vector<int>>& a) {
    check[x] = 1;
    for (auto& nx : a[x]) {
        if (check[nx] == 0) {
            foo(nx, v, a);
        }
    }
    v.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
        ra[w].push_back(q);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            foo(i, v, a);
        }
    }
    memset(check, 0, sizeof(check));
    int cnt = 0;
    while (!v.empty()) {
        vector<int> v2;
        if (check[v.back()] == 0) {
            foo(v.back(), v2, ra);
            sort(v2.begin(), v2.end());
            for (int i = 0; i < v2.size(); i++) {
                ans[v2[0]].push_back(v2[i]);
            }
            cnt++;
        }
        v.pop_back();
    }
    cout << cnt << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].size() != 0) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << -1 << '\n';
        }
    }
}