#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int check[50][50];
int a[50][50];
int empty_sell;
vector<pair<int, int>> v;
vector<pair<int, int>> ans;
int min_ans = 987654321;

pair<int, int> bfs(int level) {
    memset(check, 0, sizeof(check));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < ans.size(); i++) {
        q.push({ans[i].first, ans[i].second, 0});
        check[ans[i].first][ans[i].second] = 1;
    }
    int sum = 0;
    int max_level = 0;
    int x, y;
    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        level = get<2>(q.front());
        q.pop();
        if (check[x][y] == 1 && a[x][y] == 0) {
            sum++;
            if (max_level < level) {
                max_level = level;
            }
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && 0 <= ny && nx < n && ny < n && a[nx][ny] != 1 && check[nx][ny] == 0) {
                check[nx][ny] = 1;
                q.push({nx, ny, level + 1});
            }
        }
    }
    return {sum, max_level};
}
void foo(int x) {
    if (ans.size() == m) {
        pair<int, int> virus;
        virus = bfs(0);
        if ((empty_sell == virus.first) && min_ans > virus.second) {
            min_ans = virus.second;
        }
        return;
    }
    for (int i = x; i < v.size(); i++) {
        ans.push_back({v[i].first, v[i].second});
        foo(i + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                v.push_back({i, j});
            }
            if (a[i][j] == 0) {
                empty_sell++;
            }
        }
    }
    foo(0);
    if (min_ans == 987654321) {
        cout << -1;
        return 0;
    }
    cout << min_ans;
}