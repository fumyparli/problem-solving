#include <bits/stdc++.h>
using namespace std;

int check[10000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<pair<int, int>> q;
    q.push({s, 0});
    check[s] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int l = q.front().second;
        q.pop();
        if (x == g) {
            cout << l;
            return 0;
        }
        int nx = x + u;
        if (check[nx] == 0) {
            if (nx <= f) {
                check[nx] = 1;
                q.push({nx, l + 1});
            }
        }
        nx = x - d;
        if (check[nx] == 0) {
            if (1 <= nx) {
                check[nx] = 1;
                q.push({nx, l + 1});
            }
        }
    }
    cout << "use the stairs";
}
