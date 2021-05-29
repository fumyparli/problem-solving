#include <bits/stdc++.h>
using namespace std;
vector<int> a_;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k > 0)
            a.push_back(k);
        else
            a_.push_back(k);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(a_.begin(), a_.end());
    int sum = 0;
    for (int i = 0; i < a_.size(); i += 2) {
        if (i == (int)a_.size() - 1) {
            sum += a_[i];
        } else {
            sum += a_[i] * a_[i + 1];
        }
    }
    for (int i = 0; i < a.size(); i += 2) {
        if (i == (int)a.size() - 1) {
            sum += a[i];
        } else {
            if (a[i] == 1 || a[i + 1] == 1) {
                sum += a[i];
                sum += a[i + 1];
            } else {
                sum += a[i] * a[i + 1];
            }
        }
    }
    cout << sum;
}