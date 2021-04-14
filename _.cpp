#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;  // 192457  574896
    int topick = n - k;
    int i = 0;
    string ans = "";
    while (true) {
        int maxv = -1, maxi = -1;
        for (int j = i; j < n - topick + 1; j++) {
            if (maxv < s[j]) {
                maxv = s[j];
                maxi = j;
            }
        }
        ans += maxv;
        i = maxi + 1;
        topick--;
        if (topick == 0) break;
    }
    cout << ans;
}