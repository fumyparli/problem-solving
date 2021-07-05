#include <iostream>
using namespace std;

int a[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int k;
    for (int i = 1; i <= 50; i++) {
        cin >> a[i];
    }
    cin >> ans;
    for (int i = 1; i <= 50; i++) {
        if (a[i] == ans) {
            k = i;
        }
    }
    if (1 <= k && k <= 5)
        cout << "A+";
    if (6 <= k && k <= 15)
        cout << "A0";
    if (16 <= k && k <= 30)
        cout << "B+";
    if (31 <= k && k <= 35)
        cout << "B0";
    if (36 <= k && k <= 45)
        cout << "C+";
    if (46 <= k && k <= 48)
        cout << "C0";
    if (49 <= k && k <= 50)
        cout << "F";
}