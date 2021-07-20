#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

void foo() {
    if (a.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
        foo();
        a.pop_back();
    }
}

int main() {
    cin >> n >> m;
    foo();
}