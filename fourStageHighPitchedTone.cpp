#include <bits/stdc++.h>
using namespace std;

int foo(int x, int m, int s) {
    if (x == 3 && 2 * (m + 1) == s) {
        return 1;
    }
    if (x < 3 || 2 * (log(x) / log(3) + m + 1) < s) {
        return 0;
    }
    int ans = 0;
    if (x > 3) {
        ans += foo(x - 1, m, s + 1);
    }
    if (x % 3 == 0 && 2 * (m + 1) <= s) {
        ans += foo(x / 3, m + 1, s);
    }
    return ans;
}

int solution(int n) {
    return foo(n - 2, 0, 2);
}