#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
vector<vector<int>> a(501);
int t_arr[501];
int d[501];

int foo(int x) {
    if (d[x] != -1) return d[x];
    d[x] = t_arr[x];
    int tmp = -1;
    for (int i = 0; i < a[x].size(); i++) {
        int nx = a[x][i];
        tmp = max(tmp, foo(nx));
    }
    if (tmp != -1) d[x] += tmp;
    return d[x];
}

int main() {
    memset(d, -1, sizeof(d));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t_arr[i] = t;
        while (true) {
            int k;
            cin >> k;
            if (k == -1) break;
            a[i].push_back(k - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << foo(i) << '\n';
    }
}