#include <bits/stdc++.h>
using namespace std;

set<int> se;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for (auto& i : operations) {
        if (i[0] == 'I') {
            string s, _;
            stringstream(i) >> _ >> s;
            se.insert(stoi(s));
        } else if (i[0] == 'D' && i[2] == '1' && !se.empty()) {
            auto iter = se.end();
            se.erase(--iter);
        } else if (i[0] == 'D' && i[2] == '-' && !se.empty()) {
            auto iter = se.begin();
            se.erase(iter);
        }
    }
    if (se.empty())
        return {0, 0};
    else
        return {*(--se.end()), *se.begin()};
}