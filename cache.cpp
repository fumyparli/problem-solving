#include <bits/stdc++.h>
using namespace std;

vector<string> q;
set<string> se;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (auto& city : cities) {
        for (auto& c : city) {
            if ('A' <= c && c <= 'Z') {
                c += 32;
            }
        }
        auto se_iter = se.find(city);
        if (se_iter != se.end()) {
            answer++;
            string s;
            for (auto q_iter = q.begin(); q_iter != q.end(); q_iter++) {
                if (*q_iter == *se_iter) {
                    s = *q_iter;
                    q.erase(q_iter);
                    break;
                }
            }
            q.push_back(s);
            continue;
        } else {
            answer += 5;
        }
        if (!q.empty() && q.size() == cacheSize) {
            string s = q[0];
            q.erase(q.begin());
            se.erase(s);
        }
        if (q.size() != cacheSize) {
            q.push_back(city);
            se.insert(city);
        }
    }
    return answer;
}