#include <bits/stdc++.h>
using namespace std;

int check[31][31];
int solution(int m, int n, vector<string> board) {
    vector<vector<char>> b(31, vector<char>(31, 0));
    vector<vector<char>> a(31, vector<char>(31, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = board[i][j];
        }
    }
    int answer = 0;

    while (true) {
        int flag = 0;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (b[i][j] != 0 && b[i][j] == b[i + 1][j] && b[i][j] == b[i][j + 1] && b[i][j] == b[i + 1][j + 1]) {
                    check[i][j] = 1;
                    check[i + 1][j] = 1;
                    check[i][j + 1] = 1;
                    check[i + 1][j + 1] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0) break;
        for (int i = 0; i < n; i++) {
            int q = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (!check[j][i]) {
                    a[q--][i] = b[j][i];
                } else {
                    answer++;
                }
            }
        }
        b = a;
    }
    return answer;
}