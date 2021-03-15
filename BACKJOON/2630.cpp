#include <bits/stdc++.h>
using namespace std;

int a[128][128];

int is_same_all(int x1, int y1, int x2, int y2) {
    int k = a[x1][y1];
    int flag = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (a[i][j] != k) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) return k;
    return -1;
}
int ans[2];
void foo(int x1, int y1, int x2, int y2) {
    int tmp = is_same_all(x1, y1, x2, y2);
    if (tmp != -1) {
        ans[tmp]++;
        return;
    }
    int midx = (x1 + x2) / 2;
    int midy = (y1 + y2) / 2;
    foo(x1, y1, midx, midy);
    foo(x1, midy + 1, midx, y2);
    foo(midx + 1, y1, x2, midy);
    foo(midx + 1, midy + 1, x2, y2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    foo(0, 0, n - 1, n - 1);
    cout << ans[0] << '\n'
         << ans[1];
}