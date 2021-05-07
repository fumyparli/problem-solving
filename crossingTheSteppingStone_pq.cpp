#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
int solution(vector<int> stones, int k) {
    priority_queue<pair<int, int>> pq;
    int min = inf;
    for (int i = 0; i < k - 1; i++) pq.push({stones[i], i});
    for (int i = 0; i <= stones.size() - k; i++) {
        pq.push({stones[i + k - 1], i + k - 1});
        while (!pq.empty()) {
            if (!(i <= pq.top().second && pq.top().second <= i + k - 1))
                pq.pop();
            else
                break;
        }
        if (min > pq.top().first) min = pq.top().first;
    }
    return min;
}