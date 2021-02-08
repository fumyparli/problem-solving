#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long k) {
    k--;
    long long f = 1;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
        f *= i;
    }
    vector<int> answer;
    while (true) {
        f /= n;
        n--;
        if (n == 0) {
            answer.push_back(*a.begin());
            break;
        }
        answer.push_back(a[k / f]);
        a.erase(a.begin() + k / f);
        k %= f;
    }
    return answer;
}