#include <bits/stdc++.h>
using namespace std;

int a[51][51];
int check[51][51];
int n;

int countAll(int q, int w) {
    int cnt1 = 1;
    for (int i = q + 1; i < n; i++) {
        if (a[q][w] == a[i][w]) {
            cnt1++;
        } else {
            break;
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (a[q][w] == a[i][w]) {
            cnt1++;
        } else {
            break;
        }
    }
    int cnt2 = 1;
    for (int i = w + 1; i < n; i++) {
        if (a[q][w] == a[q][i]) {
            cnt2++;
        } else {
            break;
        }
    }
    for (int i = w - 1; i >= 0; i--) {
        if (a[q][w] == a[q][i]) {
            cnt2++;
        } else {
            break;
        }
    }
    return max(cnt1, cnt2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = 1;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (check[k][l] == 0 && abs(i - k) + abs(j - l) == 1) {
                        swap(a[i][j], a[k][l]);
                        int tmp1 = countAll(i, j);
                        int tmp2 = countAll(k, l);
                        ans = max({ans, tmp1, tmp2});
                        swap(a[i][j], a[k][l]);
                    }
                }
            }
        }
    }
    cout << ans;
}