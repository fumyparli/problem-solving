#include <bits/stdc++.h>
using namespace std;

int is_not_prime[1001];

void era() {
    is_not_prime[1] = 1;
    for (int i = 2; i <= sqrt(1000); i++) {
        if (is_not_prime[i] == 0) {
            for (int j = i * i; j <= 1000; j += i) {
                is_not_prime[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    era();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ans += !is_not_prime[k];
    }
    cout << ans;
}