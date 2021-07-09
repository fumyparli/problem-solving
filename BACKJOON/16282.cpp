#include <iostream>
using namespace std;

int main() {
    long long k;
    long long cnt = 0;
    cin >> k;
    while ((cnt + 1) < k) {
        k = (k - cnt) / 2 - 1;
        cnt++;
    }
    cout << cnt;
}