#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int solution(int distance, vector<int> rocks, int n) {
    int prev = 0;
    sort(rocks.begin(), rocks.end());
    for (int i = 0; i < rocks.size(); i++) {
        a.push_back(rocks[i] - prev);
        prev = rocks[i];
    }
    a.push_back(distance - rocks[rocks.size() - 1]);
    int st = 0;
    int ed = distance;
    while (true) {
        int mid = (st + ed) / 2;
        if (st >= ed) break;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            if (sum >= mid)
                sum = 0;
            else
                cnt++;
        }
        if (cnt <= n)
            st = mid + 1;
        else
            ed = mid;
    }
    return ed - 1;
}