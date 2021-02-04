#include <bits/stdc++.h>
using namespace std;

int parent[101];
int level[101];
priority_queue<pair<int, pair<int, int> > > pq;

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (level[x] > level[y]) swap(x, y);
    parent[x] = y;
    if (level[x] == level[y]) level[y]++;
}

int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    for (int i = 0; i < 101; i++) {
        level[i] = 1;
        parent[i] = i;
    }
    for (int i = 0; i < costs.size(); i++) {
        pq.push({-costs[i][2], {costs[i][0], costs[i][1]}});
    }
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (find(x) != find(y)) {
            merge(x, y);
            answer += cost;
        }
    }
    return answer;
}