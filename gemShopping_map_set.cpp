#include <bits/stdc++.h>
using namespace std;

set<string> all_string;
map<string, int> m;
set<int> s;
int m_len;
int min_len = 2'000'000'000;
vector<int> solution(vector<string> gems) {
    for (int i = 0; i < gems.size(); i++) {
        all_string.insert(gems[i]);
    }
    m_len = all_string.size();
    vector<int> answer(2);
    for (int i = 0; i < gems.size(); i++) {
        auto iter = m.find(gems[i]);
        int s_begin;
        if (iter == m.end()) {
            m.insert({gems[i], i});
            s.insert(i);
            s_begin = *s.lower_bound(0);
        } else {
            s.erase(iter->second);
            m.erase(iter);
            m.insert({gems[i], i});
            s.insert(i);
            s_begin = *s.lower_bound(0);
        }
        if (m.size() == m_len && min_len > i - s_begin) {
            min_len = i - s_begin;
            answer[0] = s_begin + 1;
            answer[1] = i + 1;
        }
    }
    return answer;
}