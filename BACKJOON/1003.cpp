#include <bits/stdc++.h>
using namespace std;

pair<int, int> d[41];

pair<int, int> foo(int i) {
    if (i == 0) {
        if (d[i].first == -1) d[i] = {1, 0};
        return {1, 0};
    }
    if (i == 1) {
        if (d[i].first == -1) d[i] = {0, 1};
        return {0, 1};
    }
    if (d[i].first != -1) {
        return d[i];
    }
    pair<int, int> tmp1 = foo(i - 1);
    pair<int, int> tmp2 = foo(i - 2);
    return d[i] = {tmp1.first + tmp2.first, tmp1.second + tmp2.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(d, -1, sizeof(d));
    foo(40);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n].first << ' ' << d[n].second << '\n';
    }
}