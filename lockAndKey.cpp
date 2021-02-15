#include <bits/stdc++.h>
using namespace std;

int n;

void rotate(vector<vector<vector<int>>> &k) {
    for (int l = 0; l < 3; l++) {
        vector<vector<int>> tmp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = k[l][n - j - 1][i];
            }
        }
        k[l + 1] = tmp;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    n = key.size();
    vector<vector<int>> l(lock.size() + n * 2, vector<int>(lock.size() + n * 2));
    for (int i = n; i < n + lock.size(); i++) {
        for (int j = n; j < n + lock.size(); j++) {
            l[i][j] = lock[i - n][j - n];
        }
    }
    vector<vector<vector<int>>> k(4);
    k[0] = key;
    rotate(k);

    for (int o = 0; o < 4; o++) {
        for (int i = 0; i < l.size() - n; i++) {
            for (int j = 0; j < l.size() - n; j++) {
                for (int q = i; q < i + n; q++) {
                    for (int w = j; w < j + n; w++) {
                        l[q][w] += k[o][q - i][w - j];
                    }
                }
                int flag = 0;
                for (int q = l.size() - n - lock.size(); q < l.size() - n; q++) {
                    for (int w = l.size() - n - lock.size(); w < l.size() - n; w++) {
                        if (l[q][w] != 1) {
                            flag = 1;
                        }
                    }
                }
                if (flag == 0) {
                    return true;
                }
                for (int q = i; q < i + n; q++) {
                    for (int w = j; w < j + n; w++) {
                        l[q][w] -= k[o][q - i][w - j];
                    }
                }
            }
        }
    }
    return false;
}