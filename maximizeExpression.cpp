#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check[3];
char oper[3] = {'+', '-', '*'};
vector<int> bt;
vector<string> a;
ll ans;
void foo() {
    if (bt.size() == 3) {
        auto b = a;
        for (auto bte : bt) {
            char op = oper[bte];
            for (int i = 0; i < b.size(); i++) {
                if (b[i][0] == op) {
                    if (op == '+') {
                        b[i - 1] = to_string(stoll(b[i - 1]) + stoll(b[i + 1]));
                    } else if (op == '-') {
                        b[i - 1] = to_string(stoll(b[i - 1]) - stoll(b[i + 1]));
                    } else if (op == '*') {
                        b[i - 1] = to_string(stoll(b[i - 1]) * stoll(b[i + 1]));
                    }
                    b.erase(b.begin() + i);
                    b.erase(b.begin() + i);
                    i--;
                }
            }
        }
        ans = max(ans, abs(stoll(b[0])));
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            bt.push_back(i);
            foo();
            bt.pop_back();
            check[i] = 0;
        }
    }
}

ll solution(string exp) {
    stringstream f(exp);
    string s = "";
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            a.push_back(s);
            string tmp = "";
            tmp += exp[i];
            a.push_back(tmp);
            s = "";
        } else {
            s += exp[i];
        }
    }
    a.push_back(s);
    foo();
    return ans;
}