#include <bits/stdc++.h>
using namespace std;

set<int> se;
stack<int> redo;

string solution(int n, int k, vector<string> cmd) {
    for (int i = 0; i < n; i++) se.insert(i);
    auto iter = se.begin();
    for (int i = 0; i < k; i++) iter++;

    for (auto cmd : cmd) {
        if (cmd[0] == 'D') {
            int x = stoi(cmd.substr(2));
            for (int i = 0; i < x; i++) {
                if (iter == se.end()) {
                    iter--;
                    break;
                }
                iter++;
            }
        } else if (cmd[0] == 'U') {
            int x = stoi(cmd.substr(2));
            for (int i = 0; i < x; i++) {
                if (iter == se.begin()) break;
                iter--;
            }
        } else if (cmd[0] == 'C') {
            redo.push(*iter);
            auto iter2 = ++iter;
            se.erase(--iter);
            if (iter2 == se.end()) iter2--;
            iter = iter2;
        } else if (cmd[0] == 'Z') {
            int redone = redo.top();
            redo.pop();
            se.insert(redone);
        }
    }

    vector<int> check(n, 0);
    for (auto idx : se) check[idx] = 1;
    string answer = "";
    for (auto item : check) answer += item ? 'O' : 'X';
    return answer;
}