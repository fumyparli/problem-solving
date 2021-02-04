#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > a(201, vector<int>(201));
int check[201];

void dfs(int x) {
    check[x] = 1;
    for (int i = 0; i < a[x].size(); i++) {
        int nx = a[x][i];
        if (check[nx] == 0) {
            dfs(nx);
        }
    }
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (computers[i][j] == 1) {
                a[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            answer++;
            dfs(i);
        }
    }
    return answer;
}