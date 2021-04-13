#include <bits/stdc++.h>
using namespace std;

char a[103][103];
int check[103][103];
int haskey[26];

int t, n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(haskey, 0, sizeof(haskey));
        cin >> n >> m;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                    a[i][j] = '.';
                else
                    cin >> a[i][j];
            }
        }
        string keys;
        cin >> keys;
        if (keys != "0") {
            for (int i = 0; i < keys.size(); i++) {
                haskey[keys[i] - 'a'] = 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            memset(check, 0, sizeof(check));
            queue<pair<int, int>> q;
            q.push({0, 0});
            check[0][0] = 1;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (islower(a[x][y])) {
                    haskey[a[x][y] - 'a'] = 1;
                } else if (a[x][y] == '$') {
                    cnt++;
                    a[x][y] = '.';
                }
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < n + 2 && 0 <= ny && ny < m + 2 && check[nx][ny] == 0 && a[nx][ny] != '*') {
                        if (isupper(a[nx][ny])) {
                            if (haskey[a[nx][ny] - 'A'] == 1) {
                                check[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        } else {
                            check[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}