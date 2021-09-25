#include <bits/stdc++.h>
using namespace std;

set<int> se;
vector<int> solution(vector<int> enter, vector<int> leave) {
    int leaveIdx = 0;
    vector<int> ans(enter.size() + 1);
    for (int i = 0; i < enter.size(); i++) {
        for (auto it : se) ans[it]++;
        ans[enter[i]] = se.size();
        se.insert(enter[i]);
        while (true) {
            auto iter = se.find(leave[leaveIdx]);
            if (iter == se.end()) {
                break;
            } else {
                se.erase(iter);
                leaveIdx++;
            }
        }
    }
    ans.erase(ans.begin());
    return ans;
}