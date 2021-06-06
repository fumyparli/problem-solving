#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
vector<int> t;
vector<int> t2;
int ans = 987654321;

void foo(int x) {
    if (x == n) {
        return;
    }
    if (t.size() == n / 2) {
        int check[20] = {0};
        int sum = 0, sum2 = 0;
        for (int i = 0; i < n / 2 - 1; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                sum += (a[t[i]][t[j]] + a[t[j]][t[i]]);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            check[t[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 0) {
                t2.push_back(i);
            }
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                sum2 += (a[t2[i]][t2[j]] + a[t2[j]][t2[i]]);
            }
        }
        ans = min(abs(sum - sum2), ans);
        t2.clear();
        return;
    }
    t.push_back(x);
    foo(x + 1);
    t.pop_back();
    foo(x + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    foo(0);
    cout << ans;
}