#include <bits/stdc++.h>
using namespace std;
int check[42];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++) {
        int k;
        cin >> k;
        check[k % 42] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 42; i++) {
        if (check[i] == 1)
            ans++;
    }
    cout << ans;
}