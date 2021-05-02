#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int parent[10001];
int total_money[10001];

void foo(int x, int money) {
    if (x == -1) return;
    int to_give = money / 10;
    total_money[x] += money - to_give;
    foo(parent[x], to_give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = i;
    }
    for (int i = 0; i < enroll.size(); i++) {
        int c = m[enroll[i]];
        int p;
        if (referral[i] == "-")
            p = -1;
        else
            p = m[referral[i]];
        parent[c] = p;
    }
    for (int i = 0; i < seller.size(); i++) {
        foo(m[seller[i]], amount[i] * 100);
    }
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(total_money[i]);
    }
    return answer;
}