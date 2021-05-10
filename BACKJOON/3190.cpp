#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int a[101][101];
int t[10001];
int cnt;

vector<pair<int, int>> body;

void move(int x, int y, int nx, int ny) {
    if (a[nx][ny] == 0) {  //사과가 없으면
        a[body[0].first][body[0].second] = 0;
        body.erase(body.begin(), body.begin() + 1);  //맨 끝꼬리 삭제
    }
    a[nx][ny] = 1;
    body.push_back({nx, ny});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u][v] = 2;
    }
    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        int c;
        char d;
        cin >> c >> d;
        c++;
        if (d == 'D') {
            t[c] = 1;
        } else if (d == 'L') {
            t[c] = 3;
        }
    }
    a[0][0] = 1;
    body.push_back({0, 0});
    int x = 0;
    int y = 0;
    int k = 0;
    while (true) {
        cnt++;
        if (t[cnt] != 0) {
            k = (k + t[cnt]) % 4;
        }
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {  //벽에 부딪히면 break
            cout << cnt;
            return 0;
        }
        for (int i = 0; i < body.size(); i++) {  //뱀의 머리가 몸에 부딪히면 break
            if ((nx == body[i].first) && (ny == body[i].second)) {
                cout << cnt;
                return 0;
            }
        }
        move(x, y, nx, ny);
        x = nx;
        y = ny;
    }
}