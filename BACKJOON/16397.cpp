#include <bits/stdc++.h>
using namespace std;

bool check[100000];
queue<pair<int, int>> q;

int when_B(int x) {
    if (x == 0) {
        return 0;
    }
    int re;
    int mul = 0;
    x *= 2;
    re = x;
    while (true) {
        x /= 10;
        if (x == 0) {
            return re - (int)(pow(10, mul));
        } else {
            mul++;
        }
    }
}

int main() {
    int st, t, g;
    cin >> st >> t >> g;
    q.push({st, 0});
    check[st] = 1;
    while (!q.empty()) {
        st = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > t) {
            break;
        }
        if (st == g) {
            cout << cnt;
            return 0;
        }
        if (st * 2 <= 99999) {
            int val = when_B(st);
            if (check[val] == 0) {
                q.push({val, cnt + 1});
                check[val] = 1;
            }
        }
        if (st + 1 <= 99999) {
            if (check[st + 1] == 0) {
                q.push({st + 1, cnt + 1});
                check[st + 1] = 1;
            }
        }
    }
    cout << "ANG";
}