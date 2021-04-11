#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(101001);
int check[101001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            a[n + i].push_back(v);
            a[v].push_back(n + i);
        }
    }
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == n) {
            cout << check[x];
            return 0;
        }
        for (auto &nx : a[x]) {
            if (check[nx] == 0) {
                check[nx] = check[x];
                if (nx <= n) check[nx]++;
                q.push(nx);
            }
        }
    }
    cout << -1;
}