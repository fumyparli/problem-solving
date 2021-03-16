#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k != 0) {
            pq.push({abs(k), k});
        } else {
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top().second << '\n';
            pq.pop();
        }
    }
}