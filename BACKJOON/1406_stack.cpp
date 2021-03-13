#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> left;
    stack<char> right;
    for (int i = 0; i < s.size(); i++) {
        left.push(s[i]);
    }
    int n;
    cin >> n;
    getline(cin, s, '\n');
    for (int i = 0; i < n; i++) {
        string inst;
        getline(cin, inst, '\n');
        if (inst[0] == 'L' && !left.empty()) {
            right.push(left.top());
            left.pop();
        } else if (inst[0] == 'D' && !right.empty()) {
            left.push(right.top());
            right.pop();
        } else if (inst[0] == 'B' && !left.empty()) {
            left.pop();
        } else if (inst[0] == 'P') {
            left.push(inst[2]);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}