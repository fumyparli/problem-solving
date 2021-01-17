#include <iostream>
using namespace std;

int check[26];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a') {
            check[s[i] - 'A' - 32]++;
        } else {
            check[s[i] - 'A']++;
        }
    }
    int ans;
    pair<int, int> max;
    for (int i = 0; i < 26; i++) {
        if (max.first < check[i]) {
            ans = i;
            max.first = check[i];
            max.second = 0;
        } else if (max.first == check[i]) {
            max.second++;
        }
    }
    if (max.second == 0) {
        cout << (char)(ans + 'A');
    } else {
        cout << '?';
    }
}