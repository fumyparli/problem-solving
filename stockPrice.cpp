#include <stack>
#include <vector>
using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer(p.size());
    vector<pair<int, int>> a;
    for (int i = 0; i < p.size(); i++) {
        a.push_back({p[i], i});
    }
    stack<pair<int, int>> s;
    s.push({a[0].first, a[0].second});
    for (int i = 1; i < a.size(); i++) {
        if (s.top().first > a[i].first) {
            while (true) {
                answer[s.top().second] = i - s.top().second;
                s.pop();
                if (s.empty() || s.top().first <= a[i].first) {
                    break;
                }
            }
        }
        s.push({a[i].first, a[i].second});
    }
    while (!s.empty()) {
        answer[s.top().second] = p.size() - 1 - s.top().second;
        s.pop();
    }
    return answer;
}