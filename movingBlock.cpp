#include <bits/stdc++.h>
using namespace std;

int check1[101][101];
int check2[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, 1, 1, -1};
int ddy[] = {1, 1, -1, -1};
int n;

vector<vector<int>> a;

struct info {
    int x[2];
    int y[2];
    int l;
};

info rotate(int direction, int t, info r) {
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
        g_x = r.x[t] + ddx[c_t + 3];
        g_y = r.y[t] + ddy[c_t + 3];
    }
    if (0 <= g_x && g_x < n && 0 <= g_y && g_y < n && a[g_x][g_y] == 0) {
        if (direction == 1) {
            r.x[!t] = r.x[t] + dx[(c_t + 1) % 4];
            r.y[!t] = r.y[t] + dy[(c_t + 1) % 4];
        } else {
            r.x[!t] = r.x[t] + dx[(c_t + 3) % 4];
            r.y[!t] = r.y[t] + dy[(c_t + 3) % 4];
        }
    }
    return r;
}

int solution(vector<vector<int>> aa) {
    a = aa;
    n = a.size();
    int answer = 0;
    queue<info> q;
    info k = {{0, 0}, {0, 1}, 0};
    info tmp = rotate(1, 0, k);
    cout << tmp.x[0] << ',' << tmp.y[0] << " " << tmp.x[1] << ',' << tmp.y[1];

    info k = {{0, 0}, {0, 1}, 0};
    info tmp = rotate(1, 0, k);
    cout << tmp.x[0] << ',' << tmp.y[0] << " " << tmp.x[1] << ',' << tmp.y[1];
    return answer;
}

int main() {
    solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
}