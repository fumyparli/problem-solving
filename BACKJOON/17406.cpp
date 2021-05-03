#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> a(51, vector<int>(51));
vector<tuple<int, int, int>> v;
void rotate(int r, int c, int s, vector<vector<int>> &a) {
    int x1 = r - s;
    int x2 = r + s;
    int y1 = c - s;
    int y2 = c + s;
    while (true) {
        if (x1 >= x2 || y1 >= y2) break;
        int tmp = a[x1][y2];
        for (int i = y2; i > y1; i--) {
            a[x1][i] = a[x1][i - 1];
        }
        for (int i = x1; i < x2; i++) {
            a[i][y1] = a[i + 1][y1];
        }
        for (int i = y1; i < y2; i++) {
            a[x2][i] = a[x2][i + 1];
        }
        for (int i = x2; i > x1 + 1; i--) {
            a[i][y2] = a[i - 1][y2];
        }
        a[x1 + 1][y2] = tmp;
        x1++;
        x2--;
        y1++;
        y2--;
    }
}
vector<int> bt;
int check[6];
int minv = 2'000'000'000;
void foo() {
    if (bt.size() == k) {
        auto b = a;
        for (int i = 0; i < k; i++) {
            auto [q, w, e] = v[bt[i]];
            rotate(q - 1, w - 1, e, b);
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += b[i][j];
            }
            minv = min(minv, sum);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            bt.push_back(i);
            foo();
            check[i] = 0;
            bt.pop_back();
        }
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
        int q, w, e;
        cin >> q >> w >> e;
        v.push_back({q, w, e});
    }
    foo();
    cout << minv;
}