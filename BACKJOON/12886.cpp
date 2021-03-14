#include <bits/stdc++.h>
using namespace std;

set<vector<int>> se;
int flag;
void foo(int x, int y, int z) {
    if (x == y && y == z) {
        flag = 1;
        return;
    }
    vector<int> t = {x, y, z};
    sort(t.begin(), t.end());
    if (se.find(t) != se.end()) return;
    se.insert(t);
    if (t[2] != t[1]) foo(t[1] * 2, t[2] - t[1], t[0]);
    if (t[1] != t[0]) foo(t[0] * 2, t[1] - t[0], t[2]);
    if (t[2] != t[0]) foo(t[0] * 2, t[2] - t[0], t[1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    foo(a, b, c);
    cout << flag;
}