#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> list;
bool check[10];

void foo() {
    if (a.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    int pre_n = -1;
    for (int i = 0; i < n; i++) {
        if (check[i] == 0 && pre_n != list[i]) {
            check[i] = 1;
            a.push_back(list[i]);
            foo();
            check[i] = 0;
            a.pop_back();
            pre_n = list[i];
        }
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
    foo();
}