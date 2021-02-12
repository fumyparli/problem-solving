#include <bits/stdc++.h>
using namespace std;
#define inf 1000000001

int d[1000001];

int solution(vector<int> a) {
    int answer = 0;
    int min = inf;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] < min) min = a[i];
        d[i] = min;
    }
    d[a.size()] = inf;
    int l_min = inf;
    for (int i = 0; i < a.size(); i++) {
        int cnt = 0;
        if (a[i] < l_min)
            l_min = a[i];
        else
            cnt++;
        if (a[i] > d[i + 1]) cnt++;
        if (cnt < 2) answer++;
    }
    return answer;
}