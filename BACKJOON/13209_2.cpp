#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> a(100001);
int pnum[100001];

ll dfs(int x, int &cnt, ll &mid, int prev) {
    ll total = (ll)pnum[x];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (auto nx : a[x]) {
        if (nx != prev) {
            ll tmp = dfs(nx, cnt, mid, x);
            pq.push(tmp);
        }
    }
    while (!pq.empty()) {
        ll c = pq.top();
        if (total + c > mid) break;
        pq.pop();
        total += c;
    }
    cnt += (int)pq.size();
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(pnum, 0, sizeof(pnum));
        int n, k;
        ll st = 0, ed = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            cin >> pnum[i];
            st = max(st, (ll)pnum[i]);
            ed += (ll)pnum[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int q, w;
            cin >> q >> w;
            a[q].push_back(w);
            a[w].push_back(q);
        }
        while (true) {
            if (st >= ed) break;
            ll mid = (st + ed) / 2;
            int cnt = 0;
            dfs(1, cnt, mid, -1);
            if (cnt <= k) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        cout << ed << '\n';
    }
}