#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>> pq;
multiset<int> se;  // 중복 허용해야 하니까 multiset 써야됨 주의

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int q, w;
        cin >> q >> w;
        pq.push({w, -q});
    }
    for (int i = 0; i < k; i++) {
        int w;
        cin >> w;
        se.insert(w);
    }
    long long ans = 0;
    while (true) {
        if (pq.empty() || se.size() == 0) break;
        pair<int, int> x = pq.top();
        pq.pop();
        auto iter = se.lower_bound(-x.second);
        if (iter != se.end()) {
            ans += x.first;
            se.erase(iter);
        }
    }
    cout << ans;
}