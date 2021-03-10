#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> cores) {
    int cores_size = cores.size();
    int st = 0;
    int ed = 500000000;
    while (true) {
        if (st >= ed) break;
        int mid = (st + ed) / 2;
        long long sum = 0;
        for (int i = 0; i < cores_size; i++) {
            sum += (mid / cores[i]) + 1;
        }
        if (sum >= n) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < cores_size; i++) {
        sum += (ed / cores[i]) + 1;
    }
    int iv = sum - n;
    int stidx = -1;
    for (int i = cores_size - 1; i >= 0; i--) {
        if (ed % cores[i] == 0) {
            stidx = i;
            break;
        }
    }
    for (int i = stidx; i >= 0; i--) {
        if (ed % cores[i] == 0) {
            if (iv == 0) {
                return i + 1;
            }
            iv--;
        }
    }
}