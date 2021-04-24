#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string inst;
        cin >> inst;
        int n;
        cin >> n;
        deque<int> dq;
        string k;
        cin >> k;
        k.erase(k.begin());
        k.erase(k.end() - 1);
        stringstream f(k);
        while (getline(f, k, ',')) {
            dq.push_back(stoi(k));
        }
        int turn = 0;
        int flag = 0;
        for (auto inst : inst) {
            if (inst == 'D') {
                if (dq.size() == 0) {
                    cout << "error" << '\n';
                    flag = 1;
                    break;
                }
                if (turn == 0) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            } else if (inst == 'R') {
                turn = !turn;
            }
        }
        if (flag == 1) continue;
        if (turn == 1) {
            reverse(dq.begin(), dq.end());
        }
        cout << "[";
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i];
            if (i != (int)dq.size() - 1) {
                cout << ',';
            }
        }
        cout << "]" << '\n';
    }
}