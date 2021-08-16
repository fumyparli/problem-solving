#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> table;

vector<vector<vector<pair<int, int>>>> blocks(3000, vector<vector<pair<int, int>>>(4));
int used_block[3000];

int check_block[3000][3000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

int block_idx = 2;

void paint_block(int x, int y) {
    check_block[x][y] = block_idx;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && check_block[nx][ny] == 0 && table[nx][ny] == 1) {
            paint_block(nx, ny);
        }
    }
}

void rotate_block() {
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][n - i - 1] = check_block[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check_block[i][j] = tmp[i][j];
        }
    }
}

int check_get_block[3000][3000];
void get_block(int x, int y, int stx, int sty, vector<pair<int, int>> &coords) {
    check_get_block[x][y] = 1;
    coords.push_back({x - stx, y - sty});
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && check_get_block[nx][ny] == 0 && check_block[nx][ny] != 0) {
            get_block(nx, ny, stx, sty, coords);
        }
    }
}

int check_board[3000][3000];
void get_block_in_board(int x, int y, int stx, int sty, vector<pair<int, int>> &coords) {
    check_board[x][y] = 1;
    coords.push_back({x - stx, y - sty});
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && check_board[nx][ny] == 0 && board[nx][ny] == 0) {
            get_block_in_board(nx, ny, stx, sty, coords);
        }
    }
}

void paint_board(int x, int y) {
    board[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] == 0) {
            paint_board(nx, ny);
        }
    }
}

bool judge_same_pair(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        auto [q, w] = a[i];
        auto [e, r] = b[i];
        if (q != e || w != r) return false;
    }
    return true;
}

int solution(vector<vector<int>> board2, vector<vector<int>> table2) {
    board = board2;
    table = table2;
    n = board.size();
    int blocks_num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                blocks_num++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1 && check_block[i][j] == 0) {
                paint_block(i, j);
                block_idx++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        memset(check_get_block, 0, sizeof(check_get_block));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (check_block[j][k] != 0 && check_get_block[j][k] == 0) {
                    vector<pair<int, int>> tmp;
                    get_block(j, k, j, k, tmp);
                    sort(tmp.begin(), tmp.end());
                    blocks[check_block[j][k]][i] = tmp;
                }
            }
        }
        rotate_block();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                memset(check_board, 0, sizeof(check_board));
                vector<pair<int, int>> block_in_board;
                get_block_in_board(i, j, i, j, block_in_board);
                sort(block_in_board.begin(), block_in_board.end());
                int flag = 0;
                for (int q = 2; q < block_idx; q++) {
                    if (used_block[q] == 1) continue;
                    for (int w = 0; w < 4; w++) {
                        if (judge_same_pair(block_in_board, blocks[q][w])) {
                            used_block[q] = 1;
                            paint_board(i, j);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) break;
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                answer++;
            }
        }
    }
    return answer - blocks_num;
}