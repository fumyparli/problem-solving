#include <bits/stdc++.h>
using namespace std;

vector<int> idx;
vector<int> point;

int get_idx(int x) {
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        idx.push_back(k);
        point.push_back(k);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (auto& i : point) {
        cout << get_idx(i) << " ";
    }
}