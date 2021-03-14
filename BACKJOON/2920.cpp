#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt1 = 1;
    int cnt2 = 8;
    for (int i = 0; i < 8; i++) {
        int k;
        cin >> k;
        if (cnt1 == k) cnt1++;
        if (cnt2 == k) cnt2--;
    }
    if (cnt1 == 9)
        cout << "ascending";
    else if (cnt2 == 0)
        cout << "descending";
    else
        cout << "mixed";
}