#include <bits/stdc++.h>
using namespace std;

vector<string> a;

bool cmp(string &a, string &b) {
    if (a.size() == b.size())
        return ((a + b) < (b + a));
    return a.size() < b.size();
}
bool cmp2(string &a, string &b) {
    return ((a + b) < (b + a));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    string tmp = *(a.end() - 1);
    for (int i = 0; i < n - k; i++) {
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp2);
    string answer = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        answer += a[i];
    }
    cout << answer;
}