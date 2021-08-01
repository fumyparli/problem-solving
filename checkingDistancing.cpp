#include <bits/stdc++.h>
using namespace std;

int check[6][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int l = 0; l < places.size(); l++) {
        int flag = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (flag == 1 && places[l][i][j] == 'P') {
                    memset(check, 0, sizeof(check));
                    queue<tuple<int, int, int>> q;
                    q.push({i, j, 0});
                    check[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y, d] = q.front();
                        q.pop();
                        if (places[l][x][y] == 'P' && (d == 1 || d == 2)) {
                            flag = 0;
                            break;
                        }
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && check[nx][ny] == 0 && places[l][nx][ny] != 'X') {
                                check[nx][ny] = 1;
                                q.push({nx, ny, d + 1});
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(flag);
    }
    return answer;
}