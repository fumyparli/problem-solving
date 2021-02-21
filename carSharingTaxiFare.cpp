#include <bits/stdc++.h>
using namespace std;
#define inf 700000000

int d[201][201];
vector<vector<pair<int, int>>> a(201);

int solution(int n, int s, int A, int B, vector<vector<int>> fares) {
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            if (i != j)
                d[i][j] = inf;
        }
    }
    for (int i = 0; i < fares.size(); i++) {
        a[fares[i][0]].push_back({fares[i][2], fares[i][1]});
        a[fares[i][1]].push_back({fares[i][2], fares[i][0]});
    }
    for (int l = 1; l <= n; l++) {
        priority_queue<pair<int, int>> pq;
        pq.push({0, l});
        while (!pq.empty()) {
            int x = pq.top().second;
            int dist = -pq.top().first;
            pq.pop();
            if (dist > d[l][x]) continue;
            for (int i = 0; i < a[x].size(); i++) {
                int nx = a[x][i].second;
                int nd = a[x][i].first;
                if (d[l][x] + nd < d[l][nx]) {
                    d[l][nx] = d[l][x] + nd;
                    pq.push({-d[l][nx], nx});
                }
            }
        }
    }
    int _min = inf;
    for (int k = 1; k <= n; k++) {
        int tmp = d[s][k] + d[k][A] + d[k][B];
        if (_min > tmp)
            _min = tmp;
    }
    return _min;
}