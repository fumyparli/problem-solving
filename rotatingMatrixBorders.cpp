#include <bits/stdc++.h>
using namespace std;
int a[10001][10001];
int rotate(int x1, int y1, int x2, int y2) {
    int tmp = a[x1][y2];
    int minv = tmp;
    for (int i = y2; i > y1; i--) {
        a[x1][i] = a[x1][i - 1];
        minv = min(minv, a[x1][i]);
    }
    for (int i = x1; i < x2; i++) {
        a[i][y1] = a[i + 1][y1];
        minv = min(minv, a[i][y1]);
    }
    for (int i = y1; i < y2; i++) {
        a[x2][i] = a[x2][i + 1];
        minv = min(minv, a[x2][i]);
    }
    for (int i = x2; i > x1 + 1; i--) {
        a[i][y2] = a[i - 1][y2];
        minv = min(minv, a[i][y2]);
    }
    a[x1 + 1][y2] = tmp;
    return minv;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            a[i][j] = (i - 1) * columns + j;
        }
    }
    for (auto i : queries) {
        answer.push_back(rotate(i[0], i[1], i[2], i[3]));
    }
    return answer;
}