#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> st;
    vector<char> ans;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int flag = 0;
        while (idx <= n + 1) {
            if (!st.empty() && st.top() == k) {
                ans.push_back('-');
                st.pop();
                flag = 1;
                break;
            }
            st.push(idx++);
            ans.push_back('+');
        }
        if (flag == 0) {
            cout << "NO";
            return 0;
        }
    }
    for (auto& i : ans) {
        cout << i << '\n';
    }
}