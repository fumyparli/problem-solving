#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define inf 10000000

ll get_first_divisor(int x) {
    if (x == 1) return 0;
    if (x == 2 || x == 3) return 1;
    for (int i = 2; i * i <= 1000000000; i++) {
        if (x % i == 0 && x / i <= inf) {
            return x / i;
        }
    }
    return 1;
}

vector<int> solution(ll begin, ll end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++) {
        answer.push_back(get_first_divisor(i));
    }
    return answer;
}