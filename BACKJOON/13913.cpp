#include <bits/stdc++.h>
using namespace std;

int check[100001];
int d[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    memset(check, -1, sizeof(check));
    int ans = 2'000'000'000;
    queue<int> q;
    q.push(n);
    check[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            cout << check[x] << '\n';
            break;
        }
        int nx[3] = {x + 1, x - 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            if (0 <= nx[i] && nx[i] <= 100000) {
                if (check[nx[i]] == -1) {
                    check[nx[i]] = check[x] + 1;
                    d[nx[i]] = x;
                    q.push(nx[i]);
                }
            }
        }
    }
    stack<int> st;
    int x = k;
    while (true) {
        st.push(x);
        if (x == n) break;
        x = d[x];
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}