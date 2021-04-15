#include <cstdio>
#include <cstdlib>
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, r, c, d, ans;
char a[50][50];
void dfs(int x, int y, int d) {
    if (a[x][y] == 1) {
        printf("%d", ans);
        exit(0);
    }
    if (a[x][y] != -1) {
        a[x][y] = -1;
        ans++;
    }
    c = 0;
    for (int i = 3; i >= 0; i--) {
        int k = (d + i) % 4, nx = x + dx[k], ny = y + dy[k];
        if (a[nx][ny] == 0 && a[nx][ny] != -1)
            dfs(nx, ny, k);
        else
            c++;
    }
    if (c == 4)
        dfs(x + dx[(d + 2) % 4], y + dy[(d + 2) % 4], d);
}
int main() {
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    dfs(r, c, d);
}