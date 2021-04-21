#include <bits/stdc++.h>
using namespace std;

bool check[10000];

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        queue<pair<int, string>> q;
        q.push(make_pair(a, ""));
        check[a] = 1;
        while (!q.empty()) {
            a = q.front().first;
            string s = q.front().second;
            q.pop();
            if (a == b) {
                cout << s << '\n';
                break;
            }
            int next[4];
            string k[] = {"D", "S", "L", "R"};
            next[0] = (2 * a) % 10000;
            next[1] = (a - 1 + 10000) % 10000;
            next[2] = (a / 1000) + ((a % 1000) * 10);
            next[3] = (a % 10) * 1000 + (a / 10);
            for (int j = 0; j < 4; j++) {
                if (check[next[j]] == 0) {
                    q.push(make_pair(next[j], s + k[j]));
                    check[next[j]] = 1;
                }
            }
        }
        memset(check, 0, sizeof(check));
    }
}