#include <bits/stdc++.h>
using namespace std;
int check[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct info {
    int x;
    int y;
    int d;
};
int solution(vector<vector<int>> a) {
    int answer = -1;
    int n = a.size();
    int m = a[0].size();
    queue<info> q;
    q.push({0, 0, 1});
    check[0][0] = 1;
    while (!q.empty()) {
        info r = q.front();
        q.pop();
        if (r.x == n - 1 && r.y == m - 1) {
            answer = r.d;
            break;
        }
        for (int k = 0; k < 4; k++) {
            int nx = r.x + dx[k];
            int ny = r.y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == 1) {
                check[nx][ny] = 1;
                q.push({nx, ny, r.d + 1});
            }
        }
    }
    return answer;
}