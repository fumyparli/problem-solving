#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<int> a;
vector<int> ans;

int lowerBound(int x) {
    int st = 0;
    int end = ans.size() - 1;
    while (true) {
        int mid = (st + end) / 2;
        if (st >= end) {
            break;
        }
        if (ans[mid] >= x) {
            end = mid;
        } else if (ans[mid] < x) {
            st = mid + 1;
        }
    }
    return end;
}

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
            ans[lowerBound(a[i])] = a[i];
        }
    }
    cout << ans.size();
}