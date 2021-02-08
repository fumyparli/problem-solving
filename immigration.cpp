#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long st = 0;
    long long end = *(times.end() - 1) * (long long)n;
    long long mid;
    while (st < end) {
        mid = (st + end) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) sum += mid / times[i];
        if (sum <= n - 1)
            st = mid + 1;
        else if (sum > n - 1)
            end = mid;
    }
    return end;
}