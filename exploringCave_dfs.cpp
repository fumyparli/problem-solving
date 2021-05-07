#include <bits/stdc++.h>
using namespace std;

int haveToGo[200001];
int rrel[200001];
int check[200001];
vector<vector<int>> a(200001);

void dfs(int x) {
    if (haveToGo[x]) {
        dfs(haveToGo[x]);
    }
    check[x] = 1;
    for (auto nx : a[x]) {
        if (rrel[nx] && check[rrel[nx]] == 0) {
            haveToGo[rrel[nx]] = nx;
            continue;
        }
        if (check[nx] == 0) {
            dfs(nx);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (int i = 0; i < order.size(); i++) {
        rrel[order[i][1]] = order[i][0];
        if (order[i][1] == 0) return false;
    }
    for (int i = 0; i < path.size(); i++) {
        a[path[i][0]].push_back(path[i][1]);
        a[path[i][1]].push_back(path[i][0]);
    }
    dfs(0);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            return false;
        }
    }
    return true;
}