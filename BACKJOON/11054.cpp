#include <bits/stdc++.h>
using namespace std;

int a[1001];
int d1[1001];
int d2[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        d1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d1[i] <= d1[j]) {
                d1[i] = d1[j] + 1;
            }
        }
    }
    for (int i = n; i >= 0; i--) {
        d2[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j] && d2[i] <= d2[j]) {
                d2[i] = d2[j] + 1;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (ans < d1[i] + d2[i] - 1) {
            ans = d1[i] + d2[i] - 1;
        }
    }
    cout << ans;
}