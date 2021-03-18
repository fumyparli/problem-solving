#include <bits/stdc++.h>
using namespace std;

int a[5000001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < l - 1; i++) {
        pq.push({a[i], i});
        cout << pq.top().first << " ";
    }
    for (int i = l - 1; i < n; i++) {
        pq.push({a[i], i});
        while (true) {
            pair<int, int> r = pq.top();
            if (i - l + 1 <= r.second && r.second <= i) {
                cout << r.first << " ";
                break;
            } else {
                pq.pop();
            }
        }
    }
}