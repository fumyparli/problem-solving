#include <bits/stdc++.h>
using namespace std;

int a[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int k;
            cin >> k;
            a[k] = 1;
        } else if (s == "remove") {
            int k;
            cin >> k;
            a[k] = 0;
        } else if (s == "check") {
            int k;
            cin >> k;
            if (a[k] == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (s == "toggle") {
            int k;
            cin >> k;
            if (a[k] == 1)
                a[k] = 0;
            else
                a[k] = 1;
        } else if (s == "all") {
            for (int i = 1; i <= 20; i++) {
                a[i] = 1;
            }
        } else if (s == "empty") {
            for (int i = 1; i <= 20; i++) {
                a[i] = 0;
            }
        }
    }
}