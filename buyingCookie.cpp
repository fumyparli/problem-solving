#include <bits/stdc++.h>
using namespace std;
int d[2001];
int solution(vector<int> cookie) {
    int n = cookie.size();
    for (int i = 0; i < n; i++) {
        d[i + 1] += d[i] + cookie[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int tofind = 2 * d[j];
            int idx = lower_bound(d + j, d + n + 1, tofind) - d;
            if (idx != n + 1 && d[idx] == tofind) {
                ans = max(ans, d[idx] / 2);
                continue;
            }
        }
        for (int j = i; j <= n; j++) d[j] -= cookie[i - 1];
    }
    return ans;
}