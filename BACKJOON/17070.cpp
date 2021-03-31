#include <bits/stdc++.h>
using namespace std;

int d[17][17][17][17];
int a[17][17];

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
    d[0][0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    int ret = d[i][j][k][l];
                    if (i == k && j + 1 == l) {
                        if (a[k][l + 1] == 0)
                            d[k][l][k][l + 1] += ret;
                        if (a[k + 1][l + 1] == 0 && a[k][l + 1] == 0 && a[k + 1][l] == 0)
                            d[k][l][k + 1][l + 1] += ret;
                    }
                    if (i + 1 == k && j == l) {
                        if (a[k + 1][l] == 0)
                            d[k][l][k + 1][l] += ret;
                        if (a[k + 1][l + 1] == 0 && a[k][l + 1] == 0 && a[k + 1][l] == 0)
                            d[k][l][k + 1][l + 1] += ret;
                    }
                    if (i + 1 == k && j + 1 == l) {
                        if (a[k + 1][l + 1] == 0 && a[k][l + 1] == 0 && a[k + 1][l] == 0)
                            d[k][l][k + 1][l + 1] += ret;
                        if (a[k][l + 1] == 0)
                            d[k][l][k][l + 1] += ret;
                        if (a[k + 1][l] == 0)
                            d[k][l][k + 1][l] += ret;
                    }
                }
            }
        }
    }
    cout << d[n - 2][n - 1][n - 1][n - 1] + d[n - 1][n - 2][n - 1][n - 1] + d[n - 2][n - 2][n - 1][n - 1];
}