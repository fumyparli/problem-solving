#include <bits/stdc++.h>
using namespace std;
#define inf 987654321

vector<vector<pair<int, int>>> a(20001);
priority_queue<pair<int, int>> pq;
int d[20001];
int check[20001];

int main() {
    int v, e;
    cin >> v >> e;
    int k;
    cin >> k;
    k--;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[--u].push_back({--v, w});
    }
    for (int i = 0; i < 20001; i++) {
        d[i] = inf;
    }
    pq.push({0, k});
    d[k] = 0;
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        if (check[x] == 0) {
            check[x] = 1;
            for (int i = 0; i < a[x].size(); i++) {
                int nx = a[x][i].first;
                int dist = a[x][i].second;
                if (d[x] + dist < d[nx]) {
                    d[nx] = d[x] + dist;
                    pq.push({-d[nx], nx});
                }
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (d[i] == inf)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
}