#include <bits/stdc++.h>
using namespace std;

int r, c, m;
int sum_of_shark_size, deleted_shark;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct SHARK {
    int x, y, speed, d, size;
};
int hunter_y;
vector<SHARK> shark;
bool cmp(const SHARK &a, const SHARK &b) {
    if (a.y < b.y) {
        return true;
    } else if (a.y == b.y) {
        if (a.x < b.x) {
            return true;
        } else if (a.x == b.x) {
            return a.size < b.size;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
void catch_shark() {
    hunter_y++;
    for (int i = 0; i < shark.size() - deleted_shark; i++) {
        if (shark[i].y == hunter_y) {
            shark[i].x = 300;
            shark[i].y = 300;
            deleted_shark++;
            sum_of_shark_size += shark[i].size;
            break;
        }
    }
}
void move_shark() {
    for (int i = 0; i < shark.size(); i++) {
        int speed = shark[i].speed;
        int d = shark[i].d;
        int x = shark[i].x;
        int y = shark[i].y;
        if (1 <= x && 1 <= y && x <= r && y <= c) {
            while (true) {
                int nx = x + dx[d] * speed;
                int ny = y + dy[d] * speed;
                if (1 <= nx && 1 <= ny && nx <= r && ny <= c) {
                    shark[i].x = nx;
                    shark[i].y = ny;
                    shark[i].d = d;
                    break;
                }
                if (nx < 1) {
                    speed -= (x - 1);
                    x = 1;
                    d = (d + 2) % 4;
                }
                if (nx > r) {
                    speed -= (r - x);
                    x = r;
                    d = (d + 2) % 4;
                }
                if (ny < 1) {
                    speed -= (y - 1);
                    y = 1;
                    d = (d + 2) % 4;
                }
                if (ny > c) {
                    speed -= (c - y);
                    y = c;
                    d = (d + 2) % 4;
                }
            }
        }
    }
    sort(shark.begin(), shark.end(), cmp);
    int tmp = 0;
    if (shark.size() == deleted_shark) {
        return;
    }
    for (int i = 0; i < shark.size() - deleted_shark - 1; i++) {
        if ((shark[i].x == shark[i + 1].x) && (shark[i].y == shark[i + 1].y)) {
            shark[i].x = 300;
            shark[i].y = 300;
            tmp++;
        }
    }
    deleted_shark += tmp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if (d == 1) {
            d = 0;
        } else if (d == 3) {
            d = 1;
        } else if (d == 4) {
            d = 3;
        }
        shark.push_back({r, c, s, d, z});
    }
    for (int i = 0; i < c; i++) {
        sort(shark.begin(), shark.end(), cmp);
        catch_shark();
        move_shark();
    }
    cout << sum_of_shark_size;
}