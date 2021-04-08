#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
vector<pair<int, int>> ans;

vector<int> get_pi(string p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

void kmp(string s, string p) {
    vector<int> pi = get_pi(p);
    int n = s.size();
    int m = p.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back({i - m + 1, i + 1});
                j = pi[j];
            } else {
                j++;
            }
        }
    }
}

vector<vector<int>> a(20001);
int check[20001];

int solution(vector<string> strs, string t) {
    for (auto& s : strs) {
        kmp(t, s);
    }
    for (auto& i : ans) {
        a[i.first].push_back(i.second);
    }
    for (int i = 0; i < 20001; i++) {
        check[i] = inf;
    }
    queue<int> q;
    q.push(0);
    check[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == (int)t.size()) break;
        for (auto& nx : a[x]) {
            if (check[nx] == inf) {
                check[nx] = check[x] + 1;
                q.push(nx);
            }
        }
    }
    if (check[(int)t.size()] == inf) return -1;
    return check[(int)t.size()];
}