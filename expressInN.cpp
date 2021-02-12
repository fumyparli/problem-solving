#include <bits/stdc++.h>
using namespace std;

int d[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int solution(int N, int number) {
    int answer = 0;
    if (N == number) return 1;
    vector<set<int>> se(8);

    for (int i = 0; i < 8; i++) se[i].insert(d[i] * N);

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (auto &x : se[j]) {
                for (auto &y : se[i - j - 1]) {
                    se[i].insert(x + y);
                    se[i].insert(x * y);
                    se[i].insert(x - y);
                    if (y != 0) se[i].insert(x / y);
                }
            }
        }
        if (se[i].find(number) != se[i].end()) {
            return i + 1;
        }
    }
    return -1;
}