#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(51);

int foo(int x) {
    vector<int> childs;
    for (auto nx : a[x]) {
        childs.push_back(foo(nx));
    }
    sort(childs.begin(), childs.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < childs.size(); i++) {
        ret = max(ret, childs[i] + i + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k != -1) {
            a[k].push_back(i);
        }
    }
    cout << foo(0);
}