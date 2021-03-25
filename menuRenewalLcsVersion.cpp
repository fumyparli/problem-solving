#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

// not completed

vector<string> orders;
vector<int> course;

vector<string> answer;
set<string> se;
set<string> check;
map<string, int> ma;
int d[11][11];

void findString(int i, int j, int a, int b, string &s) {
    if (d[i][j] == 0) {
        return;
    }
    if (orders[a][i] == orders[b][j]) {
        s += orders[a][i];
        findString(i - 1, j - 1, a, b, s);
    } else {
        if (d[i - 1][j] < d[i][j - 1]) {
            findString(i, j - 1, a, b, s);
        } else {
            findString(i - 1, j, a, b, s);
        }
    }
}
string ans;
void foo(int x, string &s) {
    if (ans.size() >= 2) {
        se.insert(ans);
    }
    for (int i = x; i < s.size(); i++) {
        ans.push_back(s[i]);
        foo(i + 1, s);
        ans.pop_back();
    }
}

void pushAnswer(int m, int n, int a, int b) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] >= 2) {
                string s;
                findString(i, j, a, b, s);
                reverse(s.begin(), s.end());
                foo(0, s);
            }
        }
    }
}

int makeLcs(int i, int j, int a, int b) {
    if (i == -1 || j == -1) return 0;
    if (d[i][j]) return d[i][j];
    int tmp = 0;
    if (orders[a][i] == orders[b][j]) {
        tmp = makeLcs(i - 1, j - 1, a, b) + 1;
    }
    d[i][j] = max({tmp, makeLcs(i - 1, j, a, b), makeLcs(i, j - 1, a, b)});
    return d[i][j];
}

vector<string> solution(vector<string> o, vector<int> c) {
    orders = o;
    course = c;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    for (int i = 0; i < orders.size(); i++) {
        vector<string> v;
        for (int j = i + 1; j < orders.size(); j++) {
            memset(d, 0, sizeof(d));
            se.clear();
            makeLcs(orders[i].size() - 1, orders[j].size() - 1, i, j);
            pushAnswer(orders[i].size(), orders[j].size(), i, j);
            for (auto iter = se.begin(); iter != se.end(); iter++) {
                auto k = ma.find(*iter);
                if (k == ma.end()) {
                    ma.insert({*iter, 2});
                    v.push_back(*iter);
                } else if (check.find(*iter) == check.end()) {
                    k->second++;
                }
            }
        }
        for (int l = 0; l < v.size(); l++) {
            check.insert(v[l]);
        }
    }
    for (int i = 0; i < course.size(); i++) {
        int max = 0;
        for (auto iter = ma.begin(); iter != ma.end(); iter++) {
            if (course[i] == iter->first.size() && max < iter->second) {
                max = iter->second;
            }
        }
        for (auto iter = ma.begin(); iter != ma.end(); iter++) {
            if (course[i] == iter->first.size() && max == iter->second) {
                answer.push_back(iter->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}