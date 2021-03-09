#include <bits/stdc++.h>
using namespace std;

int d[4001][4001];

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int ans = 0;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
                if (ans < d[i][j]) ans = d[i][j];
            }
        }
    }
    cout << ans;
}