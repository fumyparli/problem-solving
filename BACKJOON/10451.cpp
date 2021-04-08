#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1001);
int check[1001];
int st[1001];

int dfs(int x) {
    check[x] = 1;
    st[x] = 1;
    for (auto& nx : a[x]) {
        if (check[nx] == 0) {
            return dfs(nx);
        } else if (st[nx] == 1) {
            return 1;
        }
    }
    st[x] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));

        int ans = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            a[i].push_back(k);
        }
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0) {
                ans += dfs(i);
            }
        }
        cout << ans << '\n';
    }
}