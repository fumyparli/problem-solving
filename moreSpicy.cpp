#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    while (true) {
        if (pq.top() >= k) return answer;
        if (pq.size() == 1) break;
        int not_spicy1 = pq.top();
        pq.pop();
        int not_spicy2 = pq.top();
        pq.pop();
        pq.push(not_spicy1 + not_spicy2 * 2);
        answer++;
    }
    return -1;
}