#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (auto s : s) {
        deque<char> dq;
        string tmp = "";
        int n = s.size();
        int cnt110 = 0;
        for (int i = 0; i < n; i++) {
            if (dq.size() >= 1 && dq[dq.size() - 1] == '1' && i < n - 1 && s[i] == '1' && s[i + 1] == '0') {
                cnt110++;
                dq.pop_back();
                i++;
            } else if (dq.size() >= 2 && dq[dq.size() - 2] == '1' && dq[dq.size() - 1] == '1' && s[i] == '0') {
                cnt110++;
                dq.pop_back();
                dq.pop_back();
            } else {
                dq.push_back(s[i]);
            }
        }
        int idx = -1;
        for (int i = (int)dq.size() - 1; i >= 0; i--) {
            if (dq[i] == '0') {
                idx = i;
                break;
            }
        }
        for (int i = 0; i <= idx; i++) {
            tmp += dq[i];
        }
        for (int i = 0; i < cnt110; i++) {
            tmp += "110";
        }
        for (int i = idx + 1; i < dq.size(); i++) {
            tmp += dq[i];
        }
        answer.push_back(tmp);
    }
    return answer;
}