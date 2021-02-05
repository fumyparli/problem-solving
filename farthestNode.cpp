#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(20001);
vector<int> ans(20001);
int check[20001];

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    int max_level = 0;
    queue<pair<int, int>> q;
    q.push({1, 0});
    check[1] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int level = q.front().second;
        q.pop();
        if (max_level < level) max_level = level;
        ans[level]++;
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if (check[nx] == 0) {
                check[nx] = 1;
                q.push({nx, level + 1});
            }
        }
    }
    return ans[max_level];
}