#include <bits/stdc++.h>
using namespace std;
int a010[1000001];
int a111[1000001];
// 11010
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (auto s : s) {
        memset(a010, 0, sizeof(a010));
        memset(a111, 0, sizeof(a111));
        vector<int> a110;
        for (int i = 0; i < (int)s.size() - 2; i++) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1') {
                a111[i] = 1;
                i += 2;
            }
        }
        for (int i = 0; i < (int)s.size() - 2; i++) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0') {
                a110.push_back(i);
                i += 2;
            }
        }
        for (int i = 0; i < (int)s.size() - 2; i++) {
            if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') {
                a010[i] = 1;
            }
        }
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (a111[i] == 1) {
                if (j == a110.size()) {
                    break;
                }
                s[i + 2] = '0';
                s[a110[j] + 2] = '1';
                if (a010[a110[j] + 2] == 1) {
                    a010[a110[j] + 2] = 0;
                    a110.push_back(a110[j] + 2);
                }
                s[a110[j]] = '1';
                j++;
                answer.push_back(s);
            }
        }
    }
    return answer;
}