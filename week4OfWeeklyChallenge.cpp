#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> a(5);

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    for (int l = 0; l < table.size(); l++) {
        string s = table[l];
        string tmp = "";
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                a[l].push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(s[i]);
            }
        }
    }
    vector<int> answer(5, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < languages.size(); j++) {
            for (int k = 1; k < a[i].size(); k++) {
                if (a[i][k] == languages[j]) {
                    answer[i] += preference[j] * (6 - k);
                    break;
                }
            }
        }
    }
    int maxv = -1, maxi = -1;
    for (int i = 0; i < answer.size(); i++) {
        if (maxv < answer[i] || (maxv == answer[i] && a[maxi][0] > a[i][0])) {
            maxv = answer[i];
            maxi = i;
        }
    }
    return a[maxi][0];
}