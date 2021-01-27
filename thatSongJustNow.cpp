#include <bits/stdc++.h>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    vector<pair<int, string>> answer;
    for (auto& music : musicinfos) {
        string s[4];
        stringstream ss(music);
        for (auto& each : s)
            getline(ss, each, ',');
        int hour = stoi(s[1].substr(0, 2)) - stoi(s[0].substr(0, 2));
        int minute = stoi(s[1].substr(3, 2)) - stoi(s[0].substr(3, 2));
        int time = hour * 60 + minute;
        string k = "";
        for (int i = 0; i < s[3].size(); i++) {
            if (s[3][i] == '#') {
                s[3][i - 1] += 32;
                s[3].erase(i, 1);
            }
        }
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == '#') {
                m[i - 1] += 32;
                m.erase(i, 1);
            }
        }
        for (int i = 0; i < time / s[3].size(); i++) {
            k += s[3];
        }
        for (int i = 0; i < time % s[3].size(); i++) {
            k += s[3][i];
        }
        if (m.size() <= k.size()) {
            for (int i = 0; i <= k.size() - m.size(); i++) {
                string tmp = k.substr(i, m.size());
                if (tmp == m) {
                    answer.push_back({time, s[2]});
                    break;
                }
            }
        }
    }
    sort(answer.begin(), answer.end(), greater<pair<int, string>>());
    string none = "(None)";
    if (answer.size() == 0) return none;
    string answer_second = answer[0].second;
    for (int i = 0; i < answer.size() - 1; i++) {
        if (answer[i].first == answer[i + 1].first) {
            answer_second = answer[i + 1].second;
        }
    }
    return answer_second;
}