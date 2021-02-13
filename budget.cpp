#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (auto& i : d) {
        budget -= i;
        if (budget < 0) break;
        answer++;
    }
    return answer;
}