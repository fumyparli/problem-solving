#include <bits/stdc++.h>
using namespace std;
#define inf 100000
int check[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans = inf;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    check[n] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();
        if (x == k)
            ans = min(ans, d);
        if (0 <= x - 1 && check[x - 1] == 0) {
            check[x - 1] = 1;
            q.push({x - 1, d + 1});
        }
        if (x + 1 <= inf && check[x + 1] == 0) {
            check[x + 1] = 1;
            q.push({x + 1, d + 1});
        }
        if (2 * x <= inf && check[2 * x] == 0) {
            check[2 * x] = 1;
            q.push({2 * x, d + 1});
        }
    }
    cout << ans;
}