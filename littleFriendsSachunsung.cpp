#include <bits/stdc++.h>
using namespace std;

struct info {
    char al;
    int x;
    int y;
};

struct infoQ {
    int x;
    int y;
    int d;
    int cnt;
};

int cmp(info &a, info &b) {
    return a.al < b.al;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> b) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int check[101][101];
    string answer = "";
    vector<info> coor;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[i].size(); j++) {
            if (isupper(b[i][j])) {
                coor.push_back({b[i][j], i, j});
            }
        }
    }
    sort(coor.begin(), coor.end(), cmp);
    int flag;
    while (true) {
        flag = 0;
        for (int i = 0; i < coor.size(); i += 2) {
            memset(check, 0, sizeof(check));
            queue<infoQ> q;
            int tofind = coor[i].al;
            q.push({coor[i].x, coor[i].y, -1, -1});
            check[coor[i].x][coor[i].y] = 1;
            while (!q.empty()) {
                int x = q.front().x;
                int y = q.front().y;
                int d = q.front().d;
                int cnt = q.front().cnt;
                q.pop();
                check[x][y] = 1;
                if (cnt < 2 && x == coor[i + 1].x && y == coor[i + 1].y) {
                    answer += tofind;
                    b[coor[i].x][coor[i].y] = '.';
                    b[coor[i + 1].x][coor[i + 1].y] = '.';
                    coor.erase(coor.begin() + i, coor.begin() + i + 2);
                    i -= 2;
                    flag = 1;
                    break;
                }
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && check[nx][ny] == 0 && (b[nx][ny] == '.' || b[nx][ny] == tofind)) {
                        int direction = 0;
                        if (d != k || d == -1) direction = 1;
                        if (cnt + direction < 2)
                            q.push({nx, ny, k, cnt + direction});
                    }
                }
            }
            if (flag == 1) break;
        }
        if (coor.size() == 0) {
            break;
        }
        if (flag == 0) {
            break;
        }
    }
    if (flag == 0) return "IMPOSSIBLE";
    return answer;
}