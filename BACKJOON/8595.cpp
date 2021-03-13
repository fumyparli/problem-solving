#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && tmp.size() != 0 && isalpha(s[i - 1]) && isdigit(s[i])) {
            ans += stoi(tmp);
            tmp = "";
        }
        if (isdigit(s[i])) {
            tmp += s[i];
        }
    }
    if (ans == 0) {
        cout << ans;
        return 0;
    }
    if (tmp.size() != 0) {
        ans += stoi(tmp);
    }
    cout << ans;
}