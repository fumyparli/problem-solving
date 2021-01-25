#include <cstring>
#include <vector>
using namespace std;

int check[101][101];
int *dx;
int *dy;
int cnt;

void dfs(int x, int y, vector<vector<int>> &a, int &m, int &n) {
    check[x][y] = 1;
    cnt++;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[nx][ny] && a[x][y] && a[x][y] == a[nx][ny]) {
            dfs(nx, ny, a, m, n);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> a) {
    vector<int> answer(2, 0);
    int local_dx[] = {-1, 0, 1, 0};
    int local_dy[] = {0, 1, 0, -1};
    dx = local_dx;
    dy = local_dy;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j] && a[i][j]) {
                cnt = 0;
                answer[0]++;
                dfs(i, j, a, m, n);
                if (answer[1] < cnt) {
                    answer[1] = cnt;
                }
            }
        }
    }
    return answer;
}