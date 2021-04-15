#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(300001);
stack<int> st;
int parent[300001];
int check[300001];

void dfs(int x) {
    check[x] = 1;
    st.push(x);
    for (auto& nx : a[x]) {
        if (check[nx] == 0) {
            parent[nx] = x;
            dfs(nx);
        }
    }
}

long long solution(vector<int> cost, vector<vector<int>> e) {
    long long answer = 0;
    vector<long long> c(cost.size());
    for (int i = 0; i < cost.size(); i++) {
        c[i] = cost[i];
    }
    for (int i = 0; i < e.size(); i++) {
        a[e[i][0]].push_back(e[i][1]);
        a[e[i][1]].push_back(e[i][0]);
    }
    dfs(0);
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (x == 0) break;
        answer += abs(c[x]);
        c[parent[x]] += c[x];
        c[x] = 0;
    }
    for (int i = 0; i < c.size(); i++) {
        if (c[i] != 0) return -1;
    }
    return answer;
}