#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
vector<vector<int>> a;
int n;
int d[201][201];

int foo(int i, int j) {
    if (i == j) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    d[i][j] = inf;
    for (int k = i; k < j; k++) {
        d[i][j] = min(d[i][j], foo(i, k) + foo(k + 1, j) + a[i][0] * a[k][1] * a[j][1]);
    }
    return d[i][j];
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(d, -1, sizeof(d));
    a = matrix_sizes;
    n = a.size();
    return foo(0, n - 1);
}