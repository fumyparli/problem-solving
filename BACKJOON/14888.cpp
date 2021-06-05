#include <bits/stdc++.h>
using namespace std;

int n;
int a[11];
int op[4];
vector<int> ans;
int _max = -1000000000, _min = 1000000000;

void foo() {
    if (ans.size() == n - 1) {
        int x = a[0];
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 0) {
                x += a[i + 1];
            } else if (ans[i] == 1) {
                x -= a[i + 1];
            } else if (ans[i] == 2) {
                x *= a[i + 1];
            } else if (ans[i] == 3) {
                x /= a[i + 1];
            }
        }
        _max = max(x, _max);
        _min = min(x, _min);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) {
            continue;
        }
        ans.push_back(i);
        op[i]--;
        foo();
        ans.pop_back();
        op[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    foo();
    cout << _max << '\n'
         << _min;
}