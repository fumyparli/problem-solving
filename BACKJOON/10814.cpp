#include <bits/stdc++.h>
using namespace std;

tuple<int, int, string> a[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int age, name;
        cin >> get<0>(a[i]) >> get<2>(a[i]);
        get<1>(a[i]) = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << get<0>(a[i]) << " " << get<2>(a[i]) << '\n';
    }
}