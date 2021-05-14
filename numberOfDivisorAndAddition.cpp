#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void foo(int left, int right) {
    for (int i = left; i <= right; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt++;
        }
        if (cnt != 0 && cnt % 2 == 0) {
            ans += i;
        } else if (cnt != 0 && cnt % 2 == 1) {
            ans -= i;
        }
    }
}

int solution(int left, int right) {
    foo(left, right);
    return ans;
}