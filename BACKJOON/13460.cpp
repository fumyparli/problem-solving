#include <cstdio>
#include <queue>
using namespace std;

int n, m;
char a[10][10];
bool check[10][10][10][10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct ball {
    int rx, ry, bx, by, level;
};

void move(int &x, int &y, int &ox, int &oy, int d) {
    if (x == -1 && y == -1) {
        return;
    }
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (a[nx][ny] == 'O') {
            x = -1;
            y = -1;
            return;
        }
        if (a[nx][ny] == '#' || (nx == ox && ny == oy)) {
            break;
        }
        x = nx;
        y = ny;
    }
}

int bfs(int rx, int ry, int bx, int by) {
    queue<ball> q;
    q.push({rx, ry, bx, by, 0});
    while (!q.empty()) {
        ball now_ball = q.front();
        q.pop();
        if (now_ball.level == 10) {
            return -1;
        }
        for (int k = 0; k < 4; k++) {
            ball cb = now_ball;
            move(cb.rx, cb.ry, cb.bx, cb.by, k);
            move(cb.bx, cb.by, cb.rx, cb.ry, k);
            move(cb.rx, cb.ry, cb.bx, cb.by, k);
            if (cb.bx == -1 && cb.by == -1) {
                continue;
            } else if (cb.rx == -1 && cb.ry == -1 && cb.bx != -1 && cb.by != -1) {
                return cb.level + 1;
            } else if (!check[cb.rx][cb.ry][cb.bx][cb.by]) {
                check[cb.rx][cb.ry][cb.bx][cb.by] = 1;
                cb.level += 1;
                q.push(cb);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (a[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    int ans = bfs(rx, ry, bx, by);
    printf("%d", ans);
}