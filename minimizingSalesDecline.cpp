#include <bits/stdc++.h>
using namespace std;

long long d[300001][2];
vector<int> cost;
vector<vector<int>> a(300001);

void foo(int x) {
    if (a[x].size() == 0) {
        d[x][1] = cost[x];
        return;
    }
    long long _min = 3000000001;
    d[x][1] = cost[x];
    for (int i = 0; i < a[x].size(); i++) {
        int nx = a[x][i];
        foo(nx);
        d[x][1] += min(d[nx][0], d[nx][1]);
        _min = min(_min, d[nx][1] - d[nx][0]);
    }
    d[x][0] = d[x][1] + max(0ll, _min) - cost[x];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    cost.push_back(0);
    for (int i = 0; i < sales.size(); i++) {
        cost.push_back(sales[i]);
    }
    for (int i = 0; i < links.size(); i++) {
        a[links[i][0]].push_back(links[i][1]);
    }
    foo(1);
    answer = min(d[1][0], d[1][1]);
    return answer;
}