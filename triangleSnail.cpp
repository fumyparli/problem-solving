#include <string>
#include <vector>

using namespace std;

#include <iostream>

int dx[] = {1, 0, -1};
int dy[] = {0, 1, -1};
int a[1001][1001];
int nn;
vector<int> answer;

void foo(int x, int y, int option, int cnt, int level) {
    if (level == nn * nn) return;
    a[x][y] = cnt;
    int nx = x + dx[option];
    int ny = y + dy[option];
    if (0 <= nx && 0 <= ny && nx < nn && ny < nn && a[nx][ny] == 0)
        foo(nx, ny, option, cnt + 1, level + 1);
    else {
        foo(x, y, (option + 1) % 3, cnt, level + 1);
    }
}

void pushInAnswer(int x, int y) {
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(a[i][j]);
        }
    }
}

vector<int> solution(int n) {
    nn = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            a[i][j] = 1;
        }
    }
    foo(0, 0, 0, 1, 0);
    pushInAnswer(0, 0);
    return answer;
}