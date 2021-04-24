#include <iostream>
using namespace std;

int check[16];
int n;
int ans;

void foo(int i) {
    if (i == n + 1) {
        ans++;
        return;
    }
    int a[15] = {0};
    for (int j = 1; j <= n; j++) {
        if (check[j] != 0) {
            int t1 = j - (i - check[j]);
            int t2 = j + (i - check[j]);
            if (1 <= t1) {
                a[t1] = 1;
            }
            if (t2 <= n) {
                a[t2] = 1;
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        if ((check[j] == 0) && (a[j] == 0)) {
            check[j] = i;
            foo(i + 1);
            check[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    foo(1);
    cout << ans;
}