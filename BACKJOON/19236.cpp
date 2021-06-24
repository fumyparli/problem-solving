#include<bits/stdc++.h>
using namespace std;

struct Fish {
    int x, y;
};
vector<Fish> fish(16);
Fish shark;
vector<vector<pair<int, int>>> a(4);
int check[4][4];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans;

int move_fish(int eatx, int eaty, vector<vector<pair<int, int>>> &a, vector<Fish> &fish, Fish &shark) {
    int ret = a[eatx][eaty].first + 1;
    if (shark.x != -1 && shark.y != -1) {
        a[shark.x][shark.y].first = -1;
    }
    fish[a[eatx][eaty].first].x = -1;
    shark.x = eatx;
    shark.y = eaty;
    a[shark.x][shark.y] = {49, a[eatx][eaty].second};
    for (int i = 0; i < 16; i++) {
        int x = fish[i].x;
        if (x != -1) {
            int y = fish[i].y;
            int d = a[x][y].second;
            for (int k = d; k < d + 8; k++) {
                int kk = k % 8;
                int nx = x + dx[kk];
                int ny = y + dy[kk];
                if (0 <= nx && 0 <= ny && nx < 4 && ny < 4 && !(shark.x == nx && shark.y == ny)) {
                    if (a[nx][ny].first == -1) {
                        a[nx][ny].first = a[x][y].first;
                        a[nx][ny].second = kk;
                        a[x][y].first = -1;
                        fish[i] = {nx, ny};
                    } else {
                        int ftmp = a[nx][ny].first;
                        int stmp = a[nx][ny].second;
                        a[nx][ny].first = a[x][y].first;
                        a[nx][ny].second = kk;
                        a[x][y].first = ftmp;
                        a[x][y].second = stmp;
                        int xtmp = fish[ftmp].x;
                        int ytmp = fish[ftmp].y;
                        fish[ftmp].x = fish[i].x;
                        fish[ftmp].y = fish[i].y;
                        fish[i].x = xtmp;
                        fish[i].y = ytmp;
                    }
                    break;
                }
            }
        }
    }
    return ret;
}
void foo_shark(int x, int y, int d, vector<vector<pair<int, int>>> a, vector<Fish> fish, Fish shark, int sum) {
    vector<vector<pair<int, int>>> a2(4);
    vector<Fish> fish2(16);
    Fish shark2 = shark;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a2[i].push_back({a[i][j].first, a[i][j].second});
        }
    }
    for (int i = 0; i < 16; i++) {
        fish2[i] = fish[i];
    }
    sum += move_fish(x, y, a2, fish2, shark2);
    int flag = 0;
    int sx = shark2.x;
    int sy = shark2.y;
    while (true) {
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if (0 <= nx && 0 <= ny && nx < 4 && ny < 4) {
            if (a2[nx][ny].first != -1) {
                foo_shark(nx, ny, a2[nx][ny].second, a2, fish2, shark2, sum);
                flag = 1;
            }
        } else {
            break;
        }
        sx = nx;
        sy = ny;
    }
    if (flag == 0) {
        ans = max(ans, sum);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int ai, bi;
            cin >> ai >> bi;
            ai--;
            bi--;
            fish[ai] = {i, j};
            a[i].push_back({ai, bi});
        }
    }
    shark.x = -1;
    shark.y = -1;
    foo_shark(0, 0, a[0][0].second, a, fish, shark, 0);
    cout << ans;
}