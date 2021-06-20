#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> a[13][13];
int n, k;

struct HORSE {
    int idx, x, y, d;
};
vector<HORSE> horse;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 1;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j].first;
        }
    }
    for (int i = 0; i < k; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t3 == 2) {
            t3 = 3;
        } else if (t3 == 3) {
            t3 = 0;
        } else if (t3 == 4) {
            t3 = 2;
        }
        t1--;
        t2--;
        horse.push_back({i, t1, t2, t3});
        a[t1][t2].second.push_back(i);
    }
    int flag = 0;
    while (true) {
        if (ans > 1000) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < horse.size(); i++) {
            int x = horse[i].x;
            int y = horse[i].y;
            int d = horse[i].d;
            int idx;
            int nx = x + dx[d];
            int ny = y + dy[d];
            for (int j = 0; j < a[x][y].second.size(); j++) {
                if (a[x][y].second[j] == i) {
                    idx = j;
                }
            }
            if (a[nx][ny].first == 2 || nx < 0 || ny < 0 || nx >= n || ny >= n) {
                if (flag == 1) {
                    flag = 0;
                    continue;
                }
                horse[i].d = (d + 2) % 4;
                i--;
                flag = 1;
            } else if (a[nx][ny].first == 0 || a[nx][ny].first == 1) {
                flag = 0;
                int cnt = 0;
                for (int j = idx; j < a[x][y].second.size(); j++) {
                    a[nx][ny].second.push_back(a[x][y].second[j]);
                    for (int k = 0; k < horse.size(); k++) {
                        if (horse[k].idx == a[x][y].second[j]) {
                            horse[k].x = nx;
                            horse[k].y = ny;
                            continue;
                        }
                    }
                    cnt++;
                }
                if (a[nx][ny].second.size() >= 4) {
                    cout << ans;
                    return 0;
                }
                for (int j = 0; j < cnt; j++) {
                    a[x][y].second.pop_back();
                }
                if (a[nx][ny].first == 1) {
                    reverse(a[nx][ny].second.end() - cnt, a[nx][ny].second.end());
                }
            }
        }
        ans++;
    }
}