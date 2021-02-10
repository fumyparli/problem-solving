#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> route;
int d[1001];
int t[1001];

void foo(int x) {
    route.push_back(a[x]);
    if (t[x] != -1)
        foo(t[x]);
}

int main() {
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(k);
        d[i] = 1;
    }
    int answer = 1;
    int answer_idx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                t[i] = j;
                if (answer < d[i]) {
                    answer = d[i];
                    answer_idx = i;
                }
            }
        }
    }
    cout << answer << '\n';
    foo(answer_idx);
    reverse(route.begin(), route.end());
    for (auto& i : route) cout << i << " ";
}