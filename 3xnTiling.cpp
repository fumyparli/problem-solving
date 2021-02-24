#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long d[5001];

int solution(int n) {
    d[0] = 1;
    d[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        d[i] = (d[i - 2]) * 3;
        for (int j = 2; j <= i / 2; j++) {
            d[i] += (d[i - 2 * j]) * 2;
        }
        d[i] %= mod;
    }
    return d[n];
}