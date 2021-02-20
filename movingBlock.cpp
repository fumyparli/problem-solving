#include <bits/stdc++.h>
using namespace std;

bool check[100][100][100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, 1, 1, -1};
int ddy[] = {1, 1, -1, -1};
pair<int, int> ddd[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int n;

vector<vector<int>> a;

struct info {
    int x[2];
    int y[2];
    int l;
};

bool can_do(int x, int y, int x1, int y1, int l) {
    if (0 <= x && x < n && 0 <= x1 && x1 < n && 0 <= y && y < n && 0 <= y1 && y1 < n && a[x][y] == 0 && a[x1][y1] == 0) {
        if (check[x][y][x1][y1] == 0) {
            check[x][y][x1][y1] = 1;
            check[x1][y1][x][y] = 1;
            return true;
        }
    }
    return false;
}

pair<bool, info> rotate(int direction, int t, info r) {
    int t_x = r.x[!t] - r.x[t];
    int t_y = r.y[!t] - r.y[t];
    int c_t;
    for (int i = 0; i < 4; i++) {
        if (dx[i] == t_x && dy[i] == t_y) {
            c_t = i;
        }
    }
    int g_x, g_y;
    if (direction == 1) {
        g_x = r.x[t] + ddx[c_t];
        g_y = r.y[t] + ddy[c_t];
    } else {
        g_x = r.x[t] + ddx[(c_t + 3) % 4];
        g_y = r.y[t] + ddy[(c_t + 3) % 4];
    }
    if (0 <= g_x && g_x < n && 0 <= g_y && g_y < n && a[g_x][g_y] == 0) {
        int nx, ny;
        if (direction == 1) {
            nx = r.x[t] + dx[(c_t + 1) % 4];
            ny = r.y[t] + dy[(c_t + 1) % 4];
        } else {
            nx = r.x[t] + dx[(c_t + 3) % 4];
            ny = r.y[t] + dy[(c_t + 3) % 4];
        }
        if (can_do(r.x[t], r.y[t], nx, ny, r.l)) {
            r.x[!t] = nx;
            r.y[!t] = ny;
            r.l++;
            return {true, r};
        }
    }
    return {false, r};
}

int solution(vector<vector<int>> aa) {
    a = aa;
    n = a.size();
    int answer = 0;
    queue<info> q;
    q.push({{0, 0}, {0, 1}, 0});
    can_do(0, 0, 0, 1, 0);
    while (!q.empty()) {
        info r = q.front();
        q.pop();
        if ((r.x[0] == n - 1 && r.y[0] == n - 1) || (r.x[1] == n - 1 && r.y[1] == n - 1)) {
            return r.l;
        }
        for (int i = 0; i < 4; i++) {
            pair<bool, info> tmp = {false, r};
            pair<int, int> o = ddd[i];
            tmp = rotate(o.first, o.second, tmp.second);
            if (tmp.first) {
                q.push(tmp.second);
            }
        }

        for (int k = 0; k < 4; k++) {
            info tmp = r;  // 이거 때문에 개고생함 통째로 복사할지 바뀔지 짤 때 제대로,,,
            int nx0 = tmp.x[0] + dx[k];
            int ny0 = tmp.y[0] + dy[k];
            int nx1 = tmp.x[1] + dx[k];
            int ny1 = tmp.y[1] + dy[k];
            if (can_do(nx0, ny0, nx1, ny1, tmp.l)) {
                tmp.x[0] = nx0;
                tmp.y[0] = ny0;
                tmp.x[1] = nx1;
                tmp.y[1] = ny1;
                tmp.l++;
                q.push(tmp);
            }
        }
    }
}