#include <bits/stdc++.h>
using namespace std;

int a[1001];
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    v.push_back(1001);
    for (int i = 0; i < n; i++) {
        auto k = lower_bound(v.begin(), v.end(), a[i]);
        if (k == v.end()) {
            v.push_back(a[i]);
        } else {
            *k = a[i];
        }
    }
    cout << v.size();
}