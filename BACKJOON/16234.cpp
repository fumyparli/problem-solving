#include <bits/stdc++.h>
using namespace std;

int a[50][50];
int parent[2500];
int sum[2500][2];
int level[2500];
int flag;
int ans;

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (level[x] < level[y]) {
        swap(x, y);
    }
    parent[y] = x;
    if (level[x] == level[y]) {
        level[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        flag = 0;
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }
        memset(sum, 0, sizeof(sum));
        memset(level, 0, sizeof(level));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < n && l <= abs(a[i][j] - a[i + 1][j]) && abs(a[i][j] - a[i + 1][j]) <= r) {
                    merge(i * n + j, (i + 1) * n + j);
                    flag = 1;
                }
                if (j + 1 < n && l <= abs(a[i][j] - a[i][j + 1]) && abs(a[i][j] - a[i][j + 1]) <= r) {
                    merge(i * n + j, i * n + j + 1);
                    flag = 1;
                }
            }
        }
        if (flag == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int x = find(i * n + j);
                    sum[x][0] += a[i][j];
                    sum[x][1]++;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int x = find(i * n + j);
                    a[i][j] = sum[x][0] / (sum[x][1]);
                }
            }
            ans++;
        } else {
            cout << ans << '\n';
            return 0;
        }
    }
}