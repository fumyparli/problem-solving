#include <bits/stdc++.h>
using namespace std;
#define inf 987654321

int check[26][26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct info {
    int x;
    int y;
    int d;
    int cost;
};

int solution(vector<vector<int>> a) {
    for (auto& i : check) {
        for (auto& j : i) {
            j = inf;
        }
    }
    queue<info> q;
    q.push({0, 0, 0, 0});
    check[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int cost = q.front().cost;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int ncost;
            if ((x == 0 && y == 0) || d == k)
                ncost = cost + 100;
            else
                ncost = cost + 600;
            if (0 <= nx && nx < a.size() && 0 <= ny && ny < a.size() && check[nx][ny] >= ncost && a[nx][ny] == 0) {
                check[nx][ny] = ncost;
                q.push({nx, ny, k, ncost});
            }
        }
    }
    return check[a.size() - 1][a.size() - 1];
}