#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (maxpq.size() == minpq.size())
            maxpq.push(k);
        else
            minpq.push(k);
        if (!minpq.empty() && maxpq.top() > minpq.top()) {
            int tmp = minpq.top();
            minpq.pop();
            minpq.push(maxpq.top());
            maxpq.pop();
            maxpq.push(tmp);
        }
        cout << maxpq.top() << " ";
    }
}