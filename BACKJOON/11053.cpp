#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int d[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(k);
        d[i] = 1;
    }
    int answer = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                if (answer < d[i])
                    answer = d[i];
            }
        }
    }
    cout << answer;
}