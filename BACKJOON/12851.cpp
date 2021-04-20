#include <bits/stdc++.h>
using namespace std;

int check[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    memset(check, -1, sizeof(check));
    int ans = 2'000'000'000, cnt = -1;
    queue<int> q;
    q.push(n);
    check[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            if (check[x] < ans) {
                ans = check[x];
                cnt = 1;
            } else if (check[x] == ans) {
                cnt++;
            }
        }
        int nx[3] = {x + 1, x - 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            if (0 <= nx[i] && nx[i] <= 100000) {
                if (check[nx[i]] == -1 || check[x] + 1 <= check[nx[i]]) {
                    check[nx[i]] = check[x] + 1;
                    q.push(nx[i]);
                }
            }
        }
    }
    cout << ans << '\n'
         << cnt;
}