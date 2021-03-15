#include <iostream>
using namespace std;

int d[11];

int main() {
    d[0] = 1, d[1] = 1;
    for (int i = 2; i < 11; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}