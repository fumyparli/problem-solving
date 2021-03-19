#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    cout << max(stoi(s1), stoi(s2));
}