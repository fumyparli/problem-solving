#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(250001);
int check[250001];

pair<int, int> get_max_bfs(int x) {
    pair<int, int> ret = {-1, -1};
    queue<int> q;
    q.push(x);
    check[x] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (ret.second < check[x]) {
            ret.second = check[x];
            ret.first = x;
        }
        for (auto& nx : a[x]) {
            if (check[nx] == -1) {
                check[nx] = check[x] + 1;
                q.push(nx);
            }
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    for (auto& e : edges) {
        a[e[0]].push_back(e[1]);
        a[e[1]].push_back(e[0]);
    }
    memset(check, -1, sizeof(check));
    pair<int, int> r1 = get_max_bfs(1);
    memset(check, -1, sizeof(check));
    pair<int, int> r2 = get_max_bfs(r1.first);
    memset(check, -1, sizeof(check));
    check[r2.first] = 0;
    pair<int, int> ans1 = get_max_bfs(r1.first);
    memset(check, -1, sizeof(check));
    check[r1.first] = 0;
    pair<int, int> ans2 = get_max_bfs(r2.first);
    return max(ans1.second, ans2.second);
}