#include <bits/stdc++.h>
using namespace std;
#define inf 2'000'000'000
int dmin[202][202];
int dmax[202][202];
vector<string> a;

int foo(int i, int j) {
    if (i == j) {
        return stoi(a[i]);
    }
    if (i > 0 && a[i - 1][0] == '-') {
        if (dmin[i][j] != -1)
            return dmin[i][j];
        else
            dmin[i][j] = inf;
    } else if (i == 0 || (i > 0 && a[i - 1][0] == '+')) {
        if (dmax[i][j] != -1)
            return dmax[i][j];
        else
            dmax[i][j] = -inf;
    }

    for (int k = i; k <= j - 2; k += 2) {
        if (i > 0 && a[i - 1][0] == '-') {
            if (a[k + 1][0] == '+') {
                dmin[i][j] = min(dmin[i][j], foo(i, k) + foo(k + 2, j));
            } else if (a[k + 1][0] == '-') {
                dmin[i][j] = min(dmin[i][j], foo(i, k) - foo(k + 2, j));
            }
        } else if (i == 0 || (i > 0 && a[i - 1][0] == '+')) {
            if (a[k + 1][0] == '+') {
                dmax[i][j] = max(dmax[i][j], foo(i, k) + foo(k + 2, j));
            } else if (a[k + 1][0] == '-') {
                dmax[i][j] = max(dmax[i][j], foo(i, k) - foo(k + 2, j));
            }
        }
    }
    if (i > 0 && a[i - 1][0] == '-') {
        return dmin[i][j];
    } else if (i == 0 || (i > 0 && a[i - 1][0] == '+')) {
        return dmax[i][j];
    }
}

int solution(vector<string> arr) {
    a = arr;
    memset(dmin, -1, sizeof(dmin));
    memset(dmax, -1, sizeof(dmax));
    return foo(0, (int)arr.size() - 1);
}