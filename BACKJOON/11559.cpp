#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int check[20][10];
vector<pair<int, int>> todelete;
char a[20][10];

void dfs(int x, int y, int &cnt, char c) {
    check[x][y] = 1;
    todelete.push_back({x, y});
    cnt++;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (check[nx][ny] == 0 && a[nx][ny] == c) {
            dfs(nx, ny, cnt, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 || i == 13 || j == 0 || j == 7) {
                a[i][j] = '*';
            } else {
                char c;
                cin >> c;
                a[i][j] = c;
            }
        }
    }
    int cnt2 = 0;
    while (true) {
        int flag = 0;
        memset(check, 0, sizeof(check));
        for (int i = 1; i < 13; i++) {
            for (int j = 1; j < 7; j++) {
                int cnt = 0;
                todelete.clear();
                if (isupper(a[i][j]) && check[i][j] == 0)
                    dfs(i, j, cnt, a[i][j]);
                if (cnt >= 4) {
                    flag = 1;
                    for (auto v : todelete) {
                        a[v.first][v.second] = '.';
                    }
                }
            }
        }
        if (flag == 0) {
            cout << cnt2;
            return 0;
        }
        for (int i = 1; i < 7; i++) {
            vector<char> tmp;
            for (int j = 12; j >= 1; j--) {
                if (a[j][i] != '.') {
                    tmp.push_back(a[j][i]);
                    a[j][i] = '.';
                }
            }
            int idx = 12;
            for (auto v : tmp) {
                a[idx--][i] = v;
            }
        }
        cnt2++;
    }
}