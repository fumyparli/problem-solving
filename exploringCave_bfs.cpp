#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(200001);
int check[200001];
int rel[200001];
int later[200001];

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for (int i = 0; i < path.size(); i++) {
        a[path[i][0]].push_back(path[i][1]);
        a[path[i][1]].push_back(path[i][0]);
    }
    memset(rel, -1, sizeof(rel));
    memset(later, -1, sizeof(later));
    for (int i = 0; i < order.size(); i++) {
        rel[order[i][1]] = order[i][0];
        if (order[i][1] == 0) {
            return false;
        }
    }
    queue<int> q;
    q.push(0);
    check[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (later[x] != -1) {
            check[later[x]] = 1;
            q.push(later[x]);
        }
        for (auto& nx : a[x]) {
            if (check[rel[nx]] == 0) {
                later[rel[nx]] = nx;
                continue;
            }
            if (check[nx] == 0) {
                check[nx] = 1;
                q.push(nx);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}