#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> a(10001);
vector<vector<string>> ra(10001);

int get_iv(string &s1, string &s2, int flag) {
    int s_size = s1.size();
    if (flag == 0) {
        auto ed = lower_bound(a[s_size].begin(), a[s_size].end(), s2);
        auto st = upper_bound(a[s_size].begin(), a[s_size].end(), s1);
        return ed - st;
    } else {
        auto ed = lower_bound(ra[s_size].begin(), ra[s_size].end(), s2);
        auto st = upper_bound(ra[s_size].begin(), ra[s_size].end(), s1);
        return ed - st;
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (auto &s : words) {
        int s_size = s.size();
        a[s_size].push_back(s);
        reverse(s.begin(), s.end());
        ra[s_size].push_back(s);
    }
    for (int i = 0; i < 10001; i++) {
        sort(a[i].begin(), a[i].end());
        sort(ra[i].begin(), ra[i].end());
    }
    for (auto &s : queries) {
        string s1 = "", s2 = "";
        int s_size = s.size();
        int flag = 0;
        if (s[0] == '?') {
            flag = 1;
            reverse(s.begin(), s.end());
        }
        for (int i = 0; i < s_size; i++) {
            if (s[i] == '?') {
                s1 += 'a';
                s2 += 'z';
            } else {
                s1 += s[i];
                s2 += s[i];
            }
        }
        answer.push_back(get_iv(s1, s2, flag));
    }
    return answer;
}