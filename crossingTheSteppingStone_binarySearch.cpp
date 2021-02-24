#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int st = 1;
    int ed = 200000000;
    while (true) {
        int mid = (st + ed) / 2;
        if (st >= ed) break;
        int cnt = 0;
        int _max = -1;
        for (int i = 0; i < stones.size(); i++) {
            int k = stones[i] - mid;
            if (k < 0) k = 0;
            if (k == 0)
                cnt++;
            else
                cnt = 0;
            if (_max < cnt) _max = cnt;
        }
        if (_max >= k)
            ed = mid;
        else
            st = mid + 1;
    }
    return ed;
}