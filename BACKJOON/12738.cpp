#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<int> a;
vector<int> ans;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }
    ans.push_back(inf);
    for (int i = 0; i < n; i++) {
        if (*(ans.end() - 1) < a[i]) {
            ans.push_back(a[i]);
        } else {
            *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
        }
    }
    cout << ans.size();
}