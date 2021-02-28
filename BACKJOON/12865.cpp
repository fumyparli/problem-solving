#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int d[101][100001];
int v[101];
int w[101];

int foo(int i, int j) {
    if (i == 0) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    int tmp = 0;
    if (j >= w[i]) {
        tmp = foo(i - 1, j - w[i]) + v[i];
    }
    return d[i][j] = max(tmp, foo(i - 1, j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    memset(d, -1, sizeof(d));
    cout << foo(n, m);
}