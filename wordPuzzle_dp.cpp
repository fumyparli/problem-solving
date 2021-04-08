#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
int d[20001];
int solution(vector<string> strs, string t) {
    for (int i = 0; i < 20001; i++) {
        d[i] = inf;
    }
    for (int i = 0; i < t.size(); i++) {
        for (auto s : strs) {
            int flag = 0;
            for (int j = 0; j < s.size(); j++) {
                if (t[i - j] != s[(int)s.size() - j - 1]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                d[i] = min(d[i], d[i - s.size()] + 1);
            }
        }
    }
    if (d[t.size() - 1] == inf) return -1;
    return d[t.size() - 1];
}