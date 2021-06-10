#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>
using namespace std;

double pi = M_PI * ((double)3 / 2);
int co = (int)cos(pi);
int si = (int)sin(pi);
int b[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n;
int x, y, d, gg;
vector<pair<int, int>> v;

void foo(int x, int y, int d, int g) {
    int nnx, nny;
    int nx, ny;
    if (g == 0) {
        v.push_back({x, y});
        b[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        v.push_back({x, y});
        b[x][y] = 1;
    }
    if (g == gg) {
        return;
    }
    int m = v.size();
    int kx, ky;
    for (int i = 0; i < m; i++) {
        nx = v[i].first - x;
        ny = v[i].second - y;
        nnx = nx * co - ny * si + x;
        nny = nx * si + ny * co + y;
        if (i == 0) {
            kx = nnx;
            ky = nny;
        }
        v.push_back({nnx, nny});
        b[nnx][nny] = 1;
    }
    foo(kx, ky, d, g + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y >> x >> d >> gg;
        v.clear();
        foo(x, y, d, 0);
    }
    int ns = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (b[i][j] && b[i][j + 1] && b[i + 1][j] && b[i + 1][j + 1]) {
                ns++;
            }
        }
    }
    cout << ns;
}