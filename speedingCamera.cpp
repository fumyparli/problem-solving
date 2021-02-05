#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int answer = 1;
    int st = routes[0][0];
    int ed = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] <= ed) {
            st = routes[i][0];
            ed = min(routes[i][1], ed);
        } else {
            answer++;
            st = routes[i][0];
            ed = routes[i][1];
        }
    }
    return answer;
}