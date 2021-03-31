#include <bits/stdc++.h>
using namespace std;

int d[100001][2];

int solution(vector<int> a) {
    int n = a.size();
    if (n == 1) return a[0];
    d[0][1] = a[0];
    for (int i = 1; i < n - 1; i++) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]);
        d[i][1] = d[i - 1][0] + a[i];
    }
    int ret = max(d[n - 2][0], d[n - 2][1]);
    memset(d, 0, sizeof(d));
    d[1][1] = a[1];
    for (int i = 2; i < n; i++) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]);
        d[i][1] = d[i - 1][0] + a[i];
    }
    return max({ret, d[n - 1][0], d[n - 1][1]});
}