#include <bits/stdc++.h>
using namespace std;

int check[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        check[i] = k;
    }
    sort(check, check + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int st = lower_bound(check, check + n, k) - check;
        if (check[st] == k)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}