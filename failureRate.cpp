#include <bits/stdc++.h>
using namespace std;

int check[501];

int cmp(const pair<double, int> &a, const pair<double, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    for (auto &i : stages) {
        check[i]++;
    }
    int sum = 0;
    vector<pair<double, int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        sum += check[i];
        if (stages.size() - sum == 0)
            a[i + 1] = {0, i + 1};
        else
            a[i + 1] = {(double)check[i + 1] / (stages.size() - sum), i + 1};
    }
    a.erase(a.begin());
    sort(a.begin(), a.end(), cmp);
    for (auto &i : a) {
        answer.push_back(i.second);
    }
    return answer;
}