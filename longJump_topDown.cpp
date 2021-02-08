#include <bits/stdc++.h>
using namespace std;

int d[2001];

int foo(int i) {
    if (i == 0) return 1;
    if (i < 0) return 0;
    if (d[i]) return d[i];
    return d[i] = (foo(i - 1) + foo(i - 2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    return foo(n);
}