#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;

void foo(int n, int from, int temp, int to) {
    if (n == 1) {
        a.push_back(from);
        b.push_back(to);
        return;
    } else {
        foo(n - 1, from, to, temp);
        a.push_back(from);
        b.push_back(to);
        foo(n - 1, temp, from, to);
    }
}

vector<vector<int>> solution(int n) {
    foo(n, 1, 2, 3);
    vector<vector<int>> answer(a.size());
    for (int i = 0; i < a.size(); i++) {
        answer[i].push_back(a[i]);
        answer[i].push_back(b[i]);
    }
    return answer;
}