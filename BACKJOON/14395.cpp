#include <bits/stdc++.h>
using namespace std;
#define inf 1000000001
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0;
        return 0;
    }
    queue<pair<long long, string>> q;
    vector<string> ans;
    int ans_s = inf;
    q.push({a, ""});
    q.push({1, "/"});
    while (!q.empty()) {
        pair<long long, string> x = {q.front().first, q.front().second};
        q.pop();
        if (x.first != 0 && x.first <= b) {
            if (x.first == b && ans_s >= x.second.size()) {
                ans.push_back(x.second);
                ans_s = x.second.size();
            }
            if (x.first != 1) {
                q.push({x.first * x.first, x.second + '*'});
            }
            q.push({x.first + x.first, x.second + '+'});
        }
    }
    if (ans_s == inf) {
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
}