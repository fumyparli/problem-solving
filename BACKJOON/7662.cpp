#include <bits/stdc++.h>
using namespace std;

multiset<int> se;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char inst;
            int k;
            cin >> inst >> k;
            if (inst == 'I') {
                se.insert(k);
            } else if (inst == 'D' && !se.empty()) {
                if (k == -1)
                    se.erase(se.begin());
                if (k == 1)
                    se.erase(--se.end());
            }
        }
        if (se.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *(--se.end()) << " " << *se.begin() << '\n';
        se.clear();
    }
}