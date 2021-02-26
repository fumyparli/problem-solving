#include <bits/stdc++.h>
using namespace std;

vector<string> a;

int main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string k;
            cin >> k;
            a.push_back(k);
        }
        sort(a.begin(), a.end());
        int flag = 0;
        int a_size = a.size();
        for (int i = 0; i < a_size - 1; i++) {
            if (a[i] == a[i + 1].substr(0, a[i].size())) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}