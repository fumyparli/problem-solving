#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    for (int i = 1; i < stations.size(); i++) {
        if (stations[i] - stations[i - 1] - w * 2 - 1 > 0) {
            int k = (stations[i] - stations[i - 1] - w * 2 - 1 - 1) / (w * 2 + 1) + 1;
            answer += k;
        }
    }
    if (stations[0] - 1 - w > 0) {
        int k = (stations[0] - 1 - w - 1) / (w * 2 + 1) + 1;
        answer += k;
    }
    if (n - stations[stations.size() - 1] - w > 0) {
        int k = (n - stations[stations.size() - 1] - w - 1) / (w * 2 + 1) + 1;
        answer += k;
    }
    return answer;
}