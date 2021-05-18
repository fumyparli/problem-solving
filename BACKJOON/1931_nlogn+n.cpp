#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, w;
        cin >> q >> w;
        a.push_back({q, w});
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        auto [st, ed] = a[i];
        for (int j = i + 1; j < n; j++) {
            auto [st2, ed2] = a[j];
            if (ed <= st2) {
                cnt++;
                i = j - 1;
                break;
            }
        }
    }
    cout << cnt;
}