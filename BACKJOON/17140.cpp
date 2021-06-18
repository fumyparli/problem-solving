#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int R, C, K;
int r = 3, c = 3, ans;
pair<int, int> check[101];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> K;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        if (ans > 100) {
            cout << -1;
            return 0;
        }
        if (a[R - 1][C - 1] == K) {
            cout << ans;
            return 0;
        }
        if (r >= c) {
            int tmp = c;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    check[a[i][j]].first = a[i][j];
                    check[a[i][j]].second++;
                }
                sort(check + 1, check + 101, cmp);
                int k = 0;
                for (int j = 1; j < 101; j++) {
                    if (check[j].second != 0) {
                        a[i][k] = check[j].first;
                        a[i][k + 1] = check[j].second;
                        k += 2;
                    }
                }
                if (k > c) {
                    c = k;
                }
                for (int j = k; j < tmp; j++) {
                    a[i][j] = 0;
                }
                memset(check, 0, sizeof(check));
            }
        } else {
            int tmp = r;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    check[a[j][i]].first = a[j][i];
                    check[a[j][i]].second++;
                }
                int k = 0;
                sort(check + 1, check + 101, cmp);
                for (int j = 1; j < 101; j++) {
                    if (check[j].second != 0) {
                        a[k][i] = check[j].first;
                        a[k + 1][i] = check[j].second;
                        k += 2;
                    }
                }
                if (k > r) {
                    r = k;
                }
                for (int j = k; j < tmp; j++) {
                    a[j][i] = 0;
                }
                memset(check, 0, sizeof(check));
            }
        }
        ans++;
    }
}