#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
#define fi first
#define se second

vector<vector<int>> a;
vector<int> ch;
vector<int> ans;
int f_check[7];
int check[4][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int answer = inf;

struct info {
    int x;
    int y;
    int level;
};

pair<int, int> go(int x, int y, int k) {
    while (true) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (k == 0 && nx < 0) {
            return {x, y};
        } else if (k == 1 && ny > 3) {
            return {x, y};
        } else if (k == 2 && nx > 3) {
            return {x, y};
        } else if (k == 3 && ny < 0) {
            return {x, y};
        } else if (a[nx][ny] != 0) {
            return {nx, ny};
        }
        x = nx;
        y = ny;
    }
}

info bfs(int st_x, int st_y, int ed) {
    queue<info> q;
    q.push({st_x, st_y, 0});
    check[st_x][st_y] = 1;
    while (!q.empty()) {
        info r = q.front();
        q.pop();
        if (a[r.x][r.y] == ed) {
            a[r.x][r.y] = 0;
            return r;
        }
        for (int k = 0; k < 4; k++) {
            int nx = r.x + dx[k];
            int ny = r.y + dy[k];
            if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && check[nx][ny] == 0) {
                check[nx][ny] = 1;
                q.push({nx, ny, r.level + 1});
            }
            pair<int, int> coor = go(r.x, r.y, k);
            if (0 <= coor.fi && coor.fi < 4 && 0 <= coor.se && coor.se < 4 && check[coor.fi][coor.se] == 0) {
                check[coor.fi][coor.se] = 1;
                q.push({coor.fi, coor.se, r.level + 1});
            }
        }
    }
}

void foo(vector<vector<int>> &board, int &r, int &c) {
    if (ans.size() == ch.size()) {
        a = board;
        int sum = 0;
        info ret = {r, c, ans[0]};
        for (auto &i : ans) {
            memset(check, 0, sizeof(check));
            ret = bfs(ret.x, ret.y, i);
            sum += (ret.level + 1);
            memset(check, 0, sizeof(check));
            ret = bfs(ret.x, ret.y, i);
            sum += (ret.level + 1);
        }
        if (answer > sum) {
            answer = sum;
        }
        return;
    }
    for (int i = 0; i < ch.size(); i++) {
        if (f_check[i] == 0) {
            f_check[i] = 1;
            ans.push_back(ch[i]);
            foo(board, r, c);
            ans.pop_back();
            f_check[i] = 0;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0)
                ch.push_back(board[i][j]);
        }
    }
    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());
    foo(board, r, c);
    return answer;
}