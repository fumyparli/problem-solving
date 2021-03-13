#include <bits/stdc++.h>
using namespace std;

list<char> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a.push_back(s[i]);
    }
    int n;
    cin >> n;
    getline(cin, s, '\n');
    auto cursor = a.end();
    for (int i = 0; i < n; i++) {
        string inst;
        getline(cin, inst, '\n');
        if (inst[0] == 'L' && cursor != a.begin()) {
            cursor--;
        } else if (inst[0] == 'D' && cursor != a.end()) {
            cursor++;
        } else if (inst[0] == 'B' && cursor != a.begin()) {
            auto tmp = cursor;
            a.erase(--cursor);
            cursor = tmp;
        } else if (inst[0] == 'P') {
            a.insert(cursor, inst[2]);
        }
    }
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter;
    }
}