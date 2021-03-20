#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> a;
        vector<int> ant;
        int n, l, k;
        cin >> n >> l >> k;
        for (int i = 0; i < n; i++) {
            int q, w;
            cin >> q >> w;
            if (w > 0)
                a.push_back({l - q, 1});
            else
                a.push_back({q, 0});
            ant.push_back(w);
        }
        sort(a.begin(), a.end());
        int st = 0, ed = a.size() - 1;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            cnt++;
            if (i + 1 < a.size() && a[i].first == a[i + 1].first) {
                if (ant[st] < ant[ed]) {
                    if (cnt == k) {
                        cout << ant[st] << '\n';
                        break;
                    }
                    st++;
                } else {
                    swap(a[i], a[i + 1]);
                    if (cnt == k) {
                        cout << ant[ed] << '\n';
                        break;
                    }
                    ed--;
                }
            } else {
                if (a[i].second == 1) {
                    if (cnt == k) {
                        cout << ant[ed] << '\n';
                        break;
                    }
                    ed--;
                } else {
                    if (cnt == k) {
                        cout << ant[st] << '\n';
                        break;
                    }
                    st++;
                }
            }
        }
    }
}