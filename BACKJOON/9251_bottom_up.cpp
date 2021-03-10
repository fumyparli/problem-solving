#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
string s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int s1_size = s1.size();
    int s2_size = s2.size();
    for (int i = 1; i < s1_size; i++) {
        for (int j = 1; j < s2_size; j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
            }
        }
    }
    cout << d[s1_size - 1][s2_size - 1] << '\n';
}