#include <bits/stdc++.h>
using namespace std;

bool is_true(deque<char>& dq, char op1, char op2) {
    stack<char> st;
    int flag = 0;
    for (int i = 0; i < dq.size(); i++) {
        if (dq[i] == op1 || dq[i] == op2) flag = 1;
    }
    if (flag == 0) return 0;
    for (int i = 0; i < dq.size(); i++) {
        if (dq[i] == op2 && !st.empty() && st.top() == op1) {
            st.pop();
        } else if (dq[i] == op1) {
            st.push(dq[i]);
        }
    }
    if (!st.empty()) {
        return 0;
    }
    return 1;
}

bool is_right(deque<char>& dq) {
    if (!is_true(dq, '(', ')')) return 0;
    if (!is_true(dq, '{', '}')) return 0;
    if (!is_true(dq, '[', ']')) return 0;
    return 1;
}

int solution(string s) {
    int ans = 0;
    deque<char> dq;
    for (int i = 0; i < s.size(); i++) {
        dq.push_back(s[i]);
    }
    for (int i = 0; i < dq.size(); i++) {
        if (is_right(dq)) ans++;
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    return ans;
}