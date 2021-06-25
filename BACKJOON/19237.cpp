#include<bits/stdc++.h>
using namespace std;

vector<int> a[20][20];
struct Shark {
    int x, y, d, p[4][4];
};
vector<Shark> shark(400);

struct Smell {
    int idx, cnt;
};
Smell smell[30][30];

struct To_set_smell {
    int x, y, idx;
};
queue<To_set_smell> q;

int n, m, time_smell_out;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool judge_and_go(int i, int jud) {
    int x = shark[i].x;
    int y = shark[i].y;
    int flag = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[shark[i].p[shark[i].d][k]];
        int ny = y + dy[shark[i].p[shark[i].d][k]];
        if (0 <= nx && 0 <= ny && nx < n && ny < n) {
            if ((jud == 0 && smell[nx][ny].idx == -1) || (jud == 1 && smell[nx][ny].idx == i)) {
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].d = shark[i].p[shark[i].d][k];
                a[nx][ny].push_back(i);
                a[x][y].resize(0);
                q.push({nx, ny, i});
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void go() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].x != -1) {
            if (!judge_and_go(i, 0)) {
                judge_and_go(i, 1);
            }
        }
    }
}

void foo() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].x != -1) {
            int x = shark[i].x;
            int y = shark[i].y;
            smell[x][y] = {i, time_smell_out};
        }
    }
    go();
    while (!q.empty()) {
        To_set_smell aa = q.front();
        q.pop();
        smell[aa.x][aa.y] = {aa.idx, time_smell_out};
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (smell[i][j].idx != -1 && --smell[i][j].cnt == 0) {
                smell[i][j].idx = -1;
            }
            if (a[i][j].size() > 1) {
                int strong_shark = 987654321;
                for (int k = 0; k < a[i][j].size(); k++) {
                    strong_shark = min(strong_shark, a[i][j][k]);
                }
                for (int k = 0; k < a[i][j].size(); k++) {
                    if (a[i][j][k] != strong_shark) {
                        shark[a[i][j][k]].x = -1;
                    }
                }
                a[i][j].resize(0);
                a[i][j].push_back(strong_shark);
            }
        }
    }
}

void set_d(int &d) {
    if (d == 1) {
        d = 0;
    } else if (d == 4) {
        d = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(smell, -1, sizeof(smell));
    for (int i = 0; i < shark.size(); i++) {
        shark[i].x = -1;
    }
    cin >> n >> m >> time_smell_out;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx;
            cin >> idx;
            idx--;
            if (idx != -1) {
                a[i][j].push_back(idx);
                shark[idx] = {i, j};
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        set_d(d);
        shark[i].d = d;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            int jtmp = j;
            if (jtmp == 1) {
                jtmp = 2;
            } else if (jtmp == 2) {
                jtmp = 3;
            } else if (jtmp == 3) {
                jtmp = 1;
            }
            for (int k = 0; k < 4; k++) {
                int d;
                cin >> d;
                set_d(d);
                shark[i].p[jtmp][k] = d;
            }
        }
    }
    for (int i = 0; i <= 1000; i++) {
        int cnt = 0;
        for (int i = 0; i < shark.size(); i++) {
            if (shark[i].x != -1) {
                cnt++;
            }
        }
        if (cnt == 1) {
            cout << i << '\n';
            return 0;
        }
        foo();
    }
    cout << -1 << '\n';
}