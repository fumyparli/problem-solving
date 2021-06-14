#include <bits/stdc++.h>
#define inf 987654321
using namespace std;

int a[20][20];
int check[20][20];
int n, timer;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct Shark {
    int x, y, level, exp;
};
Shark shark;

struct Q {
    int x, y, t;
};

void bfs(int x, int y, int t) {
    queue<Q> q;
    check[x][y] = inf;
    q.push({x, y, t});
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        t = q.front().t;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (shark.level >= a[nx][ny] && check[nx][ny] == 0) {
                    check[nx][ny] = t + 1;
                    q.push({nx, ny, t + 1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                shark = {i, j, 2, 0};
                a[i][j] = 0;
            }
        }
    }
    int min;
    int x, y;
    while (true) {
        memset(check, 0, sizeof(check));
        bfs(shark.x, shark.y, 0);
        min = inf;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (min > check[i][j] && check[i][j] != 0 && shark.level > a[i][j] && a[i][j] != 0) {
                    min = check[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        if (min == inf) {
            cout << timer;
            return 0;
        }
        shark.exp++;
        shark.x = x;
        shark.y = y;
        if (check[x][y] != inf) {
            timer += check[x][y];
        }
        a[x][y] = 0;
        if (shark.exp == shark.level) {
            shark.level++;
            shark.exp = 0;
        }
    }
}
