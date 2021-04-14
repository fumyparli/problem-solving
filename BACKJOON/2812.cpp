#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> se;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<char> dq;
    for (int i = 0; i < n; i++) {
        while (true) {
            if (k == 0 || dq.empty() || dq.back() >= s[i]) {
                dq.push_back(s[i]);
                break;
            }
            dq.pop_back();
            k--;
        }
    }
    for (int i = 0; i < dq.size() - k; i++) {
        cout << dq[i];
    }
}