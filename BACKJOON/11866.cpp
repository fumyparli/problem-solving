#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    k--;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    int st = k;
    cout << '<';
    while (true) {
        if (a.size() != 1) {
            cout << a[st] << ", ";
        } else {
            cout << a[st] << '>';
            break;
        }
        a.erase(a.begin() + st);
        st = (st + k) % a.size();
    }
}