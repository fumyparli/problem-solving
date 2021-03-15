#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (true) {
        q.pop();
        if (q.size() == 1) break;
        int f = q.front();
        q.pop();
        q.push(f);
    }
    cout << q.front();
}