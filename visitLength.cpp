#include <bits/stdc++.h>
using namespace std;

int a[11][11][11][11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int h[26];

int solution(string dirs) {
    h['R' - 'A'] = 1;
    h['D' - 'A'] = 2;
    h['L' - 'A'] = 3;
    int answer = 0;
    int x = 5, y = 5;
    for (int i = 0; i < dirs.size(); i++) {
        int nx = x + dx[h[dirs[i] - 'A']];
        int ny = y + dy[h[dirs[i] - 'A']];
        if (0 <= nx && nx < 11 && 0 <= ny && ny < 11) {
            if (a[x][y][nx][ny] == 0 && a[nx][ny][x][y] == 0) {
                a[x][y][nx][ny] = 1;
                a[nx][ny][x][y] = 1;
                answer++;
            }
            x = nx;
            y = ny;
        }
    }
    return answer;
}
