#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> a(301, vector<int>(301));
void rotate() {
    int x1 = 0;
    int x2 = n - 1;
    int y1 = 0;
    int y2 = m - 1;
    while (true) {
        if (x1 >= x2 || y1 >= y2) break;
        int tmp = a[x1][y1];
        for (int i = y1; i < y2; i++) {
            a[x1][i] = a[x1][i + 1];
        }
        for (int i = x1; i < x2; i++) {
            a[i][y2] = a[i + 1][y2];
        }
        for (int i = y2; i > y1; i--) {
            a[x2][i] = a[x2][i - 1];
        }
        for (int i = x2; i > x1 + 1; i--) {
            a[i][y1] = a[i - 1][y1];
        }
        a[x1 + 1][y1] = tmp;
        x1++;
        x2--;
        y1++;
        y2--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        rotate();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}