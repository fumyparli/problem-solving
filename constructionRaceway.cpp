#include <bits/stdc++.h>
using namespace std;

int check[26][26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int solution(vector<vector<int>> a) {
    int n = a.size();
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, -1, 0});
    check[0][0] = 1;
    while (!q.empty()) {
        auto [x, y, d, cost] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ncost = cost + 100;
            if (d != -1 && d != k) ncost += 500;
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] == 0) {
                if (check[nx][ny] == 0 || check[nx][ny] >= ncost) {
                    check[nx][ny] = ncost;
                    q.push({nx, ny, k, ncost});
                }
            }
        }
    }
    return check[n - 1][n - 1];
}