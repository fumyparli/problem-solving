#include <bits/stdc++.h>
using namespace std;

int m;

string makeBinary(int n) {
    string s;
    while (true) {
        if (n == 0) break;
        s += (n % 2) + '0';
        n /= 2;
    }
    while (true) {
        if (s.size() == m) break;
        s += '0';
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    m = n;
    vector<string> answer(n);
    vector<string> a1;
    vector<string> a2;
    for (auto& i : arr1) a1.push_back(makeBinary(i));
    for (auto& i : arr2) a2.push_back(makeBinary(i));
    for (int i = 0; i < a1.size(); i++) {
        for (int j = 0; j < a1[i].size(); j++) {
            if (a1[i][j] == '1' || a2[i][j] == '1') {
                answer[i] += '#';
            } else {
                answer[i] += ' ';
            }
        }
    }
    return answer;
}