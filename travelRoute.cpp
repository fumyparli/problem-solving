#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> m;
map<pair<string, string>, int> check;
vector<string> ans;
vector<string> ret;
int n;

void dfs(string x) {
    if (ans.size() == n && ret.size() == 0) {
        int flag = 0;
        for (int i = 0; i < m[x].size(); i++) {
            if (check[{x, m[x][i]}] != 0) {
                ans.push_back(m[x][i]);
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            ret = ans;
        }
        return;
    }
    for (int i = 0; i < m[x].size(); i++) {
        string nx = m[x][i];
        if (check[{x, nx}] != 0) {
            ans.push_back(nx);
            check[{x, nx}]--;
            dfs(nx);
            ans.pop_back();
            check[{x, nx}]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back(tickets[i][1]);
        if (check.find({tickets[i][0], tickets[i][1]}) == check.end()) {
            check[{tickets[i][0], tickets[i][1]}] = 1;
        } else {
            check[{tickets[i][0], tickets[i][1]}]++;
        }
    }
    for (auto &i : m) {
        sort(i.second.begin(), i.second.end());
    }
    ans.push_back("ICN");
    dfs("ICN");
    return ret;
}