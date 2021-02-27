#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
vector<pair<int, int>> a;
vector<int> b;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, w;
        cin >> q >> w;
        a.push_back({q, w});
    }
    sort(a.begin(), a.end());
    b.push_back(inf);
    for (int i = 0; i < a.size(); i++) {
        auto k = upper_bound(b.begin(), b.end(), a[i].second);
        if (k == b.end()) {
            b.push_back(a[i].second);
        } else {
            *k = a[i].second;
        }
    }
    cout << n - b.size();
}