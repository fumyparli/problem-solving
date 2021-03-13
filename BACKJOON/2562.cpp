#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxv = -1, maxi = -1;
    for (int i = 0; i < 9; i++) {
        int k;
        cin >> k;
        if (maxv < k) {
            maxv = k;
            maxi = i + 1;
        }
    }
    cout << maxv << '\n'
         << maxi;
}