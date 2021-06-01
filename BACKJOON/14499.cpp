#include <iostream>
using namespace std;

int n, m, x, y, k;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int map[21][21];
int dice[6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int order;
        cin >> order;
        int nx = x + dx[order];
        int ny = y + dy[order];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            x = nx;
            y = ny;
            int tmp;
            if (order == 1) {
                tmp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[2];
                dice[2] = dice[0];
                dice[0] = tmp;
            }
            if (order == 2) {
                tmp = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[0];
                dice[0] = tmp;
            }
            if (order == 3) {
                tmp = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[0];
                dice[0] = tmp;
            }
            if (order == 4) {
                tmp = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[0];
                dice[0] = tmp;
            }

            if (map[x][y] == 0) {
                map[x][y] = dice[0];
            } else {
                dice[0] = map[x][y];
                map[x][y] = 0;
            }
            cout << dice[5] << '\n';
        }
    }
}