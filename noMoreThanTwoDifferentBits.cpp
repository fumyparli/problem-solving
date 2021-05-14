#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll foo(string s) {
    ll ret = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        ret += ((ll)s[i] - '0') << i;
    }
    return ret;
}
vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for (auto number : numbers) {
        string s = "";
        for (int i = 0; i < 64; i++) {
            if (number & (1L << i)) {
                s += '1';
            } else {
                s += '0';
            }
        }
        reverse(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                idx = i;
                break;
            }
        }
        int flag = 0;
        for (int i = (int)s.size() - 1; i > idx; i--) {
            if (s[i] == '0') {
                flag = 1;
                string k = s;
                k[i] = '1';
                if (i != (int)s.size() - 1) {
                    k[i + 1] = '0';
                }
                answer.push_back(foo(k));
                break;
            }
        }
        if (flag == 0) {
            s[idx] = '0';
            s[idx - 1] = '1';
            answer.push_back(foo(s));
        }
    }
    return answer;
}