#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

vector<int> a;
vector<int> ans;
vector<pair<int, int>> trace;
vector<int> answer;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
            trace.push_back({ans.size() - 1, a[i]});
        } else {
            int idx = lowerBound(a[i]);
            ans[idx] = a[i];
            trace.push_back({idx, a[i]});
        }
    }
    cout << ans.size() << '\n';
    int k = ans.size() - 1;
    for (int i = trace.size() - 1; i >= 0; i--) {
        if (trace[i].first == k) {
            answer.push_back(trace[i].second);
            k--;
        }
    }
    reverse(answer.begin(), answer.end());
    for (auto& i : answer) {
        cout << i << " ";
    }
}