#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int n = 0;
    for (int i = 0; i < gems.size(); i++) {
        if (ma[gems[i]] == 0) {
            ma[gems[i]] = 1;
            n++;
        }
    }
    int st = 0, ed = 0, cnt = 0;
    int ans = 1'000'000;
    pair<int, int> ansarr;
    while (ed < gems.size()) {
        if (ma[gems[ed]] == 1) {
            cnt++;
        }
        ma[gems[ed++]]++;
        if (cnt == n) {
            if (ans > ed - st) {
                ans = ed - st;
                answer = {st + 1, ed};
            }
            while (true) {
                ma[gems[st]]--;
                if (ma[gems[st]] == 1) {
                    cnt--;
                    st++;
                    break;
                }
                st++;
                if (ans > ed - st) {
                    ans = ed - st;
                    answer = {st + 1, ed};
                }
            }
        }
    }
    return answer;
}