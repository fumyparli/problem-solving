#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<vector<vector<string>>> v(21, vector<vector<string>>(11));
vector<string> o;
vector<int> c;
string ans;
map<string, int> m;

void foo(int x, int guest, int limit, string &s) {
    if (ans.size() == limit) {
        v[guest][limit].push_back(ans);
    }
    for (int i = x; i < s.size(); i++) {
        ans.push_back(s[i]);
        foo(i + 1, guest, limit, s);
        ans.pop_back();
    }
}

vector<string> solution(vector<string> od, vector<int> co) {
    o = od;
    c = co;
    for (int i = 0; i < o.size(); i++) {
        sort(o[i].begin(), o[i].end());
    }
    for (int i = 0; i < o.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            foo(0, i, c[j], o[i]);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            for (int k = 0; k < v[i][c[j]].size(); k++) {
                auto iter = m.find(v[i][c[j]][k]);
                if (iter == m.end()) {
                    m.insert({v[i][c[j]][k], 1});
                } else {
                    iter->second++;
                }
            }
        }
    }
    vector<string> answer;
    for (int i = 0; i < c.size(); i++) {
        int max = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (c[i] == iter->first.size() && max < iter->second) {
                max = iter->second;
            }
        }
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (c[i] == iter->first.size() && max > 1 && max == iter->second) {
                answer.push_back(iter->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}