#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> list;

void foo(int x) {
    if (a.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = x; i < n; i++) {
        a.push_back(list[i]);
        foo(i);
        a.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        list.push_back(k);
    }
    sort(list.begin(), list.end());
    foo(0);
}