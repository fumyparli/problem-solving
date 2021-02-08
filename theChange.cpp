#include <bits/stdc++.h>
using namespace std;

int d[100001];

int solution(int n, vector<int> m) {
    int answer = 0;
    d[0] = 1;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (j - m[i] >= 0)
                d[j] += d[j - m[i]];
        }
    }
    return d[n];
}