#include <bits/stdc++.h>
using namespace std;

void makeLower(string& s) {
    for (auto& c : s) {
        if ('A' <= c && c <= 'Z') {
            c += 32;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, int, int, string>> a;
    for (int i = 0; i < files.size(); i++) {
        string tmp = files[i];
        makeLower(tmp);
        string s_head = "";
        int s_number = 0;
        int next_j;
        for (int j = 0; j < tmp.size(); j++) {
            if ('0' <= tmp[j] && tmp[j] <= '9') {
                s_head = tmp.substr(0, j);
                next_j = j;
                break;
            }
        }
        s_number = stoi(tmp.substr(next_j, 6));
        a.push_back({s_head, s_number, i, files[i]});
    }
    stable_sort(a.begin(), a.end());
    for (auto& s : a) {
        answer.push_back(get<3>(s));
    }
    return answer;
}