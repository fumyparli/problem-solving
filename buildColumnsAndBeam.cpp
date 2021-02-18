#include <bits/stdc++.h>
using namespace std;

int a[110][110];
int b[110][110];
int n;

int check_build(int x, int y, int p) {
    if (p == 0) {
        if (b[x][y - 1] == 1 || b[x][y] == 1 || a[x - 1][y] == 1 || x == 2) {
            return 1;
        }
    } else {
        if (a[x - 1][y] == 1 || a[x - 1][y + 1] == 1 || (b[x][y - 1] == 1 && b[x][y + 1] == 1)) {
            return 2;
        }
    }
    return 0;
}

void _destroy(int x, int y, int p) {
    if (p == 0)
        a[x][y] = 0;
    else
        b[x][y] = 0;
    int flag = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (a[i + 2][j + 2] == 1 && !check_build(i + 2, j + 2, 0)) {
                flag = 1;
                break;
            }
            if (b[i + 2][j + 2] == 1 && !check_build(i + 2, j + 2, 1)) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    if (flag == 1) {
        if (p == 0) {
            a[x][y] = 1;
        } else {
            b[x][y] = 1;
        }
    }
}

void manage_all(int x, int y, int p, int inst) {
    if (inst == 1) {
        int ck = check_build(x, y, p);
        if (ck == 1) {
            a[x][y] = 1;
        } else if (ck == 2) {
            b[x][y] = 1;
        }
    } else {
        _destroy(x, y, p);
    }
}

vector<vector<int>> solution(int nn, vector<vector<int>> board) {
    n = nn;
    vector<vector<int>> answer;
    for (int i = 0; i < board.size(); i++) {
        int x = board[i][1];
        int y = board[i][0];
        int p = board[i][2];
        int inst = board[i][3];
        manage_all(x + 2, y + 2, p, inst);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (a[i + 2][j + 2] == 1) {
                answer.push_back({j, i, 0});
            }
            if (b[i + 2][j + 2] == 1) {
                answer.push_back({j, i, 1});
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}