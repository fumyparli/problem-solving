#include <bits/stdc++.h>
using namespace std;
int n, j, pi[1000001];
char p[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i < n; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }
    cout << n - pi[n - 1];
}