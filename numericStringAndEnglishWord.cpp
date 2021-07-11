#include <bits/stdc++.h>
using namespace std;

map<string, int> ma = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
int solution(string s) {
    string ans = "";
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            ans += s[i];
        } else {
            tmp += s[i];
            if (ma.find(tmp) != ma.end()) {
                ans += ma[tmp] + '0';
                tmp = "";
            }
        }
    }
    return stoi(ans);
}