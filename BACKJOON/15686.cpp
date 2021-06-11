#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<pair<int, int>> vv;
vector<int> c;
int ans = 987654321;
bool check[13];

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

void foo(int x) {
    if (c.size() == m) {
        int sum = 0;
        for (int i = 0; i < vv.size(); i++) {
            int tmp = 987654321;
            for (int j = 0; j < c.size(); j++) {
                if (abs(v[c[j]].first - vv[i].first) + abs(v[c[j]].second - vv[i].second) < tmp) {
                    tmp = abs(v[c[j]].first - vv[i].first) + abs(v[c[j]].second - vv[i].second);
                }
            }
            sum += tmp;
        }
        if (ans > sum) {
            ans = sum;
        }
        return;
    }
    for (int i = x; i < v.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            c.push_back(i);
            foo(i);
            c.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            scanf("%d", &k);
            if (k == 2) {
                v.push_back({i, j});
            }
            if (k == 1) {
                vv.push_back({i, j});
            }
        }
    }
    foo(0);
    printf("%d", ans);
}