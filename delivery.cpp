#include <bits/stdc++.h>
using namespace std;
#define inf 987654321;

int d[51];
int check[51];
vector<vector<pair<int, int>>> a(51);

void foo(int x) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        if (check[x] == 0) {
            check[x] = 1;
            for (int i = 0; i < a[x].size(); i++) {
                int dist = a[x][i].first;
                int nx = a[x][i].second;
                if (d[x] + dist < d[nx]) {
                    d[nx] = d[x] + dist;
                    pq.push({-d[nx], nx});
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> road, int k) {
    int answer = 0;
    for (int i = 0; i < road.size(); i++) {
        a[road[i][0]].push_back({road[i][2], road[i][1]});
        a[road[i][1]].push_back({road[i][2], road[i][0]});
    }
    for (int i = 2; i <= n; i++) {
        d[i] = inf;
    }
    foo(1);
    for (int i = 1; i <= n; i++) {
        if (d[i] <= k) answer++;
    }
    return answer;
}