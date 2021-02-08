#include <bits/stdc++.h>
using namespace std;

int d[2001];

long long solution(int n) {
    d[0] = 1;
    for (int i = 1; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % 1234567;
    return d[n];
}