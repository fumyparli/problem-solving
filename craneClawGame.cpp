#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> a, vector<int> moves) {
    int n = a.size();
    int m = a[0].size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < moves.size(); i++) {
        int pick = moves[i] - 1;
        for (int j = 0; j < n; j++) {
            if (a[j][pick] != 0) {
                if (!st.empty() && st.top() == a[j][pick]) {
                    ans += 2;
                    st.pop();
                } else {
                    st.push(a[j][pick]);
                }
                a[j][pick] = 0;
                break;
            }
        }
    }
    return ans;
}