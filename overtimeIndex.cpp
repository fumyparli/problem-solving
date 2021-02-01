#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for (auto& i : works) {
        q.push(i);
    }
    while (!q.empty()) {
        if (n == 0) break;
        int tmp = q.top();
        if (tmp == 0) break;
        q.pop();
        q.push(--tmp);
        n--;
    }
    while (!q.empty()) {
        int tmp = q.top();
        q.pop();
        answer += pow(tmp, 2);
    }
    return answer;
}