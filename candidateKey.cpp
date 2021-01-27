#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int m, n;
int answer;
vector<vector<string>> r;
vector<int> check;

void foo(int x, int limit) {
    int bit_a = 0;
    for (auto& a : ans) {
        bit_a |= 1 << a;
    }
    for (auto& c : check) {
        if ((c & bit_a) == c) return;
    }
    if (ans.size() == limit) {
        set<string> st;
        for (int i = 0; i < m; i++) {
            string s;
            for (auto& a : ans) {
                s += r[i][a];
            }
            st.insert(s);
        }
        if (st.size() == m) {
            check.push_back(0);
            for (auto& a : ans) {
                *(check.end() - 1) |= 1 << a;
            }
            answer++;
        }
    }
    for (int i = x; i < n; i++) {
        ans.push_back(i);
        foo(i + 1, limit);
        ans.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    m = relation.size();
    n = relation[0].size();
    r = relation;
    for (int i = 1; i <= n; i++) {
        foo(0, i);
    }
    return answer;
}