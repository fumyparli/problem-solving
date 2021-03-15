#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        m[k]++;
    }
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int k;
        cin >> k;
        cout << m[k] << " ";
    }
}