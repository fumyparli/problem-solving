#include <bits/stdc++.h>
using namespace std;
#define inf 700000000

int d[201][201];

int solution(int n, int s, int A, int B, vector<vector<int>> fares) {
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            if (i != j)
                d[i][j] = inf;
        }
    }
    for (int i = 0; i < fares.size(); i++) {
        d[fares[i][1]][fares[i][0]] = d[fares[i][0]][fares[i][1]] = fares[i][2];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int _min = inf;
    for (int k = 1; k <= n; k++) {
        int tmp = d[s][k] + d[k][A] + d[k][B];
        if (_min > tmp)
            _min = tmp;
    }
    return _min;
}