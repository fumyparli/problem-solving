#include <iostream>
using namespace std;

char ans[5000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        if (x == 0) {
            cout << '!';
            return 0;
        }
        ans[i] = 'A';
        x--;
    }
    n--;
    while (x > 0) {
        if (n < 0) {
            cout << '!';
            return 0;
        }
        if (x >= 26) {
            x -= 25;
            ans[n] += 25;
            n--;
        } else {
            ans[n] += x;
            x = 0;
        }
    }
    cout << ans;
}