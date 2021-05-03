#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> a(101, vector<int>(101));
void foo(int option) {
    vector<vector<int>> b(101, vector<int>(101));
    if (option == 1) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[n - i - 1][j];
                b[n - i - 1][j] = a[i][j];
            }
        }
        a = b;
    } else if (option == 2) {
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n; j++) {
                b[j][i] = a[j][m - i - 1];
                b[j][m - i - 1] = a[j][i];
            }
        }
        a = b;
    } else if (option == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][n - i - 1] = a[i][j];
            }
        }
        a = b;
        swap(n, m);
    } else if (option == 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[m - j - 1][i] = a[i][j];
            }
        }
        a = b;
        swap(n, m);
    } else if (option == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n / 2 && j < m / 2) {
                    b[i][j] = a[i + n / 2][j];
                }
                if (i < n / 2 && j >= m / 2) {
                    b[i][j] = a[i][j - m / 2];
                }
                if (i >= n / 2 && j >= m / 2) {
                    b[i][j] = a[i - n / 2][j];
                }
                if (i >= n / 2 && j < m / 2) {
                    b[i][j] = a[i][j + m / 2];
                }
            }
        }
        a = b;
    } else if (option == 6) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n / 2 && j < m / 2) {
                    b[i][j] = a[i][j + m / 2];
                }
                if (i < n / 2 && j >= m / 2) {
                    b[i][j] = a[i + n / 2][j];
                }
                if (i >= n / 2 && j >= m / 2) {
                    b[i][j] = a[i][j - m / 2];
                }
                if (i >= n / 2 && j < m / 2) {
                    b[i][j] = a[i - n / 2][j];
                }
            }
        }
        a = b;
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
        int inst;
        cin >> inst;
        foo(inst);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}