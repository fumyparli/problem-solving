#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string s;
        cin >> s;
        if (s == "0") return 0;
        int iv = (int)s.size() / 2;
        string k;
        if (s.size() % 2 == 1)
            k = s.substr(iv + 1, iv);
        else
            k = s.substr(iv, iv);
        reverse(k.begin(), k.end());
        if (s.substr(0, iv) == k)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}