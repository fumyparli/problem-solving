#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<vector<int>>> a(51, vector<vector<int>>(51));
map<int, tuple<int, int, int, int, int>> fireball;
int idx;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt;  // n*n격자, m: 파이어볼 개수, k: 이동 명령 개수
    cin >> n >> m >> cnt;
    for (int i = 0; i < m; i++) {
        int r, c, w, s, d;
        cin >> r >> c >> w >> s >> d;
        r--;
        c--;
        fireball[idx] = {r, c, w, s, d};
        a[r][c].push_back(idx++);
    }
    for (int l = 0; l < cnt; l++) {
        // 이동
        vector<vector<vector<int>>> tmp(51, vector<vector<int>>(51));
        for (auto &fireball : fireball) {
            auto &[r, c, w, s, d] = fireball.second;
            int nx = (r + dx[d] * s) % n;
            int ny = (c + dy[d] * s) % n;
            nx = (n + nx) % n;
            ny = (n + ny) % n;
            tmp[nx][ny].push_back(fireball.first);
            r = nx;
            c = ny;
        }
        a = tmp;

        // 합침
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j].size() > 1) {
                    int even_flag = 1;
                    int odd_flag = 1;
                    int total_sum = 0, total_s = 0, nd = 0;
                    for (int k = 0; k < a[i][j].size(); k++) {
                        auto &[r, c, w, s, d] = fireball[a[i][j][k]];
                        total_sum += w;
                        total_s += s;
                        nd += d;
                        if (d % 2 == 0)
                            odd_flag = 0;
                        else
                            even_flag = 0;
                        fireball.erase(a[i][j][k]);
                    }
                    total_sum /= 5;
                    total_s /= (int)a[i][j].size();
                    a[i][j].clear();
                    if (total_sum == 0) {
                        continue;
                    }
                    if (odd_flag == 1 || even_flag == 1)
                        nd = 0;
                    else
                        nd = 1;
                    for (int k = 0; k < 4; k++) {
                        fireball.insert({idx, {i, j, total_sum, total_s, nd + k * 2}});
                        a[i][j].push_back({idx++});
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto fireball : fireball) {
        auto &[r, c, w, s, d] = fireball.second;
        ans += w;
    }
    cout << ans;
}