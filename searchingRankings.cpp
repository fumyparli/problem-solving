#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> a(50000);
vector<vector<string>> b(100000);
map<vector<string>, vector<int>> m;
vector<int> tmp(0);
vector<string> ans(4);

void foo(int x, vector<string> &v, int point) {
    if (x == 4) {
        if (m.find(ans) == m.end())
            m.insert({ans, tmp});
        m[ans].push_back(point);
        return;
    }
    ans[x] = v[x];
    foo(x + 1, v, point);
    ans[x] = "-";
    foo(x + 1, v, point);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());
    for (int i = 0; i < info.size(); i++) {
        string tmp = "";
        for (int j = 0; j < info[i].size(); j++) {
            if (info[i][j] == ' ') {
                a[i].push_back(tmp);
                tmp = "";
            } else {
                tmp += info[i][j];
            }
        }
        foo(0, a[i], stoi(tmp));
    }
    for (auto &iter : m) {
        sort(iter.second.begin(), iter.second.end());
    }
    for (int i = 0; i < query.size(); i++) {
        string tmp = "";
        for (int j = 0; j < query[i].size(); j++) {
            if (query[i][j] == ' ') {
                b[i].push_back(tmp);
                tmp = "";
                if (b[i].size() != 4) {
                    j += 4;
                }
            } else {
                tmp += query[i][j];
            }
        }
        auto found = lower_bound(m[b[i]].begin(), m[b[i]].end(), stoi(tmp));
        answer[i] = m[b[i]].end() - found;
    }
    return answer;
}