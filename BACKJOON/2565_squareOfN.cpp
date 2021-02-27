#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
int d[501];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, w;
        cin >> q >> w;
        a.push_back({q, w});
    }
    sort(a.begin(), a.end());
    fill(d, d + 501, 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].second < a[i].second && d[i] <= d[j]) d[i] = d[j] + 1;
            if (ans < d[i]) ans = d[i];
        }
    }
    cout << n - ans;
}