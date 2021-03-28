#include <bits/stdc++.h>
using namespace std;

int check[4][4];
char a[4][4];
int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
int point_board[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
unordered_map<int, string> ma;

int dfs(int x, int y, string &s, int i) {
    check[x][y] = 1;
    if (i == s.size() - 1) {
        return true;
    }
    int tmp = 0;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && check[nx][ny] == 0 && a[nx][ny] == s[i + 1]) {
            tmp = max(tmp, dfs(nx, ny, s, i + 1));
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ma[i] = s;
    }
    int m;
    cin >> m;
    for (int l = 0; l < m; l++) {
        int point = 0;
        string long_str = "";
        unordered_set<string> str_check;
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            cin >> s;
            for (int j = 0; j < 4; j++) {
                a[i][j] = s[j];
            }
        }
        for (int k = 0; k < n; k++) {
            string s = ma[k];
            memset(check, 0, sizeof(check));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (check[i][j] == 0 && a[i][j] == s[0]) {
                        if (dfs(i, j, s, 0)) {
                            if (str_check.find(s) == str_check.end()) {
                                str_check.insert(s);
                                if (long_str.size() < s.size() || (long_str.size() == s.size() && long_str > s))
                                    long_str = s;
                                point += point_board[s.size()];
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << point << " " << long_str << " " << cnt << '\n';
    }
}