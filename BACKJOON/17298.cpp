#include <bits/stdc++.h>
using namespace std;
#define inf 2'000'000'000
int a[1000001];
int b[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    st.push(inf);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty()) {
            if (a[i] >= st.top()) {
                st.pop();
            } else {
                b[i] = st.top();
                break;
            }
        }
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == inf)
            cout << -1 << " ";
        else
            cout << b[i] << " ";
    }
}