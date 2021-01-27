#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> info;
map<string, string> m;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (auto& r : record) {
        string s[3];
        stringstream(r) >> s[0] >> s[1] >> s[2];
        if (!strcmp(s[0].c_str(), "Enter")) {
            info.push_back({1, s[1]});
            m[s[1]] = s[2];
        }
        if (!strcmp(s[0].c_str(), "Leave")) {
            info.push_back({0, s[1]});
        }
        if (!strcmp(s[0].c_str(), "Change")) {
            m[s[1]] = s[2];
        }
    }
    for (auto& in : info) {
        string s = m[in.second];
        if (in.first) {
            s += "님이 들어왔습니다.";
        } else {
            s += "님이 나갔습니다.";
        }
        answer.push_back(s);
    }
    return answer;
}