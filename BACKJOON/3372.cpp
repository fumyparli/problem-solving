#include <bits/stdc++.h>
using namespace std;

int a[101][101];
string d[101][101];

string bigInteger(string n, string m) {
    string ans = "";
    if (n.length() < m.length()) swap(n, m);
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    int a = 0, b = 0, carry = 0;
    for (int i = 0; i < n.length(); i++) {
        a = n[i] - 48;
        b = i < m.length() ? m[i] - 48 : 0;
        ans += (a + b + carry) % 10 + 48;
        carry = (a + b + carry) / 10;
        if (carry == 1 && i == (n.length() - 1)) {
            ans += '1';
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int n;

string foo(int i, int j) {
    if (i == n - 1 && j == n - 1) return "1";
    if (i >= n || j >= n) return "0";
    if (a[i][j] == 0) return "0";
    if (d[i][j] != "-1") return d[i][j];
    return d[i][j] = bigInteger(foo(i + a[i][j], j), foo(i, j + a[i][j]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : d) {
        for (auto &j : i) {
            j = "-1";
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << foo(0, 0);
}