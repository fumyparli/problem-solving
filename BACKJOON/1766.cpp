#include <bits/stdc++.h>
using namespace std;

int ind[32001];
vector<vector<int>> a(32001);
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
        ind[w]++;
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        cout << x << " ";
        for (auto& nx : a[x]) {
            if (--ind[nx] == 0) pq.push(nx);
        }
    }
}