#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> fuck[4][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, -1}}};

int n, m, ans;
int a[500][500];
int check[500][500];
vector<int> v;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (v.size() == 4) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            //cout << v[i] << " ";
            sum += v[i];
        }
        ans = max(ans, sum);
        //cout << '\n';
        return;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && 0 <= ny && nx < n && ny < m && check[nx][ny] == 0) {
            check[nx][ny] = 1;
            v.push_back(a[nx][ny]);
            dfs(nx, ny);
            v.pop_back();
            check[nx][ny] = 0;
        }
    }
}

void cal_fuck(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int nx = x + fuck[i][j].first;
            int ny = y + fuck[i][j].second;
            if (0 > nx || 0 > ny || nx >= n || ny >= m) {
                sum = -1;
                break;
            }
            sum += a[nx][ny];
        }
        if (sum != -1) {
            ans = max(ans, sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /*cout << '\n'
                 << '(' << i << ',' << j << ')' << '\n';*/
            check[i][j] = 1;
            v.push_back(a[i][j]);
            dfs(i, j);
            v.pop_back();
            check[i][j] = 0;
            cal_fuck(i, j);
        }
    }
    cout << ans;
}