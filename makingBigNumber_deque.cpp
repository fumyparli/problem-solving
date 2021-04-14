#include <bits/stdc++.h>
using namespace std;

string solution(string s, int k) {
    string answer = "";
    deque<char> dq;
    for (int i = 0; i < s.size(); i++) {
        while (true) {
            if (k == 0 || dq.empty() || dq.back() >= s[i]) {
                dq.push_back(s[i]);
                break;
            }
            dq.pop_back();
            k--;
        }
    }
    for (int i = 0; i < dq.size() - k; i++) {
        answer += dq[i];
    }
    return answer;
}