#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> solution(vector<int> enter, vector<int> leave) {
    int enterIdx = 0, leaveIdx = 0;
    vector<int> ans(enter.size() + 1);
    while (leaveIdx < leave.size()) {
        while (true) {
            int flag = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == leave[leaveIdx]) {
                    leaveIdx++;
                    a.erase(a.begin() + i);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) break;
        }
        if (enterIdx != enter.size()) {
            ans[enter[enterIdx]] = a.size();
            for (int i = 0; i < a.size(); i++) {
                ans[a[i]]++;
            }
            a.push_back(enter[enterIdx++]);
        }
    }
    ans.erase(ans.begin());
    return ans;
}