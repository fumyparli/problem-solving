#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

int n, m, cnt;
int check[51][51];
vector<vector<int>> a;
int ans_block1[3][2][3] = {
    {{1, 0, 0}, {1, 1, 1}},
    {{0, 0, 1}, {1, 1, 1}},
    {{0, 1, 0}, {1, 1, 1}}};
int ans_block2[2][3][2] = {
    {{0, 1}, {0, 1}, {1, 1}},
    {{1, 0}, {1, 0}, {1, 1}}};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> need_col[5] = {{1, 2}, {0, 1}, {0, 2}, {-1, 0}, {-1, 1}};

vector<pair<int, int>> blocks;
void dfs(int x, int y, int c) {
    blocks.push_back({x, y});
    check[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0 && a[nx][ny] == c) {
            dfs(nx, ny, c);
        }
    }
}

vector<pair<int, int>> make_block() {
    int xiv = inf, yiv = inf;
    for (int i = 0; i < blocks.size(); i++) {
        xiv = min(xiv, blocks[i].first);
        yiv = min(yiv, blocks[i].second);
    }
    vector<pair<int, int>> tmp;
    for (int i = 0; i < blocks.size(); i++) {
        tmp.push_back({blocks[i].first - xiv, blocks[i].second - yiv});
    }
    return tmp;
}

pair<int, int> get_minxy() {
    int min_r = inf, min_c = inf;
    for (int i = 0; i < blocks.size(); i++) {
        min_r = min(min_r, blocks[i].first);
        min_c = min(min_c, blocks[i].second);
    }
    return {min_r, min_c};
}

pair<int, int> where_need(vector<pair<int, int>> &tmp) {
    auto [min_r, min_c] = get_minxy();
    for (int i = 0; i < 3; i++) {
        int flag = 0;
        for (int j = 0; j < tmp.size(); j++) {
            int x = tmp[j].first;
            int y = tmp[j].second;
            if (x < 0 || x >= 2 || y < 0 || y >= 3 || ans_block1[i][x][y] == 0) {
                flag = 1;
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                if (ans_block1[i][j][k] == 0 && a[min_r + j][min_c + k] != 0) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            return need_col[i];
        }
    }
    for (int i = 0; i < 2; i++) {
        int flag = 0;
        for (int j = 0; j < tmp.size(); j++) {
            int x = tmp[j].first;
            int y = tmp[j].second;
            if (x < 0 || x >= 3 || y < 0 || y >= 2 || ans_block2[i][x][y] == 0) {
                flag = 1;
                break;
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                if (ans_block2[i][j][k] == 0 && a[min_r + j][min_c + k] != 0) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            return need_col[i + 3];
        }
    }
    return {-1, -1};
}

bool can_col(int y, int x) {
    int flag = 0;
    for (int i = 0; i < x; i++) {
        if (a[i][y] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return 1;
    return 0;
}

int solution(vector<vector<int>> board) {
    a = board;
    n = board.size();
    m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                memset(check, 0, sizeof(check));
                blocks.clear();
                dfs(i, j, a[i][j]);
                sort(blocks.begin(), blocks.end());
                auto tmp = make_block();
                pair<int, int> r = where_need(tmp);
                if (!(r.first == -1 && r.second == -1)) {
                    auto [x, min_c] = get_minxy();
                    int flag = 0;
                    if (r.first != -1) {
                        int y = min_c + r.first;
                        if (can_col(y, x) == 0) flag = 1;
                    }
                    int y = min_c + r.second;
                    if (can_col(y, x) == 0) flag = 1;
                    if (flag == 0) {
                        cnt++;
                        for (int k = 0; k < blocks.size(); k++) {
                            int x = blocks[k].first;
                            int y = blocks[k].second;
                            a[x][y] = 0;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}