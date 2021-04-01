#include <bits/stdc++.h>
using namespace std;

int d[14];

int solution(int n) {
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            d[i] += d[j] * d[i - j - 1];
        }
    }
    return d[n];
}