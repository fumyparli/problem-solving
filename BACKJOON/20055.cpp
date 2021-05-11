#include <bits/stdc++.h>
using namespace std;
deque<int> a;
deque<int> robot;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n * 2; i++) {
        int c;
        cin >> c;
        a.push_back(c);
    }
    for (int i = 0; i < n; i++) {
        robot.push_back(0);
    }
    int cnt = 1;
    while (true) {
        robot.pop_back();
        robot.push_front(0);
        a.push_front(a.back());
        a.pop_back();
        for (int i = n - 2; i >= 0; i--) {
            if (robot[i] == 1 && robot[i + 1] == 0 && a[i + 1] != 0) {
                robot[i + 1] = 1;
                robot[i] = 0;
                a[i + 1]--;
            }
        }
        if (a[0] != 0) {
            robot[0] = 1;
            a[0]--;
        }
        int cnt2 = 0;
        for (int i = 0; i < n * 2; i++) {
            if (a[i] == 0) {
                cnt2++;
            }
        }
        if (cnt2 >= k) {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
}