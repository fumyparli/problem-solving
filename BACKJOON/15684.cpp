#include <iostream>
using namespace std;

bool z[31][11];
int n, m, h;
int ns = 4;

int foo2(int i, int j) {
    for (int i = 1; i <= h; i++) {
        if (z[i][j] == 1) {
            j++;
        } else if (z[i][j - 1] == 1) {
            j--;
        }
    }
    return j;
}

void foo(int x, int y, int level, int ll) {
    if (ns != 4) {
        return;
    }
    if (level > ll) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i != foo2(1, i)) {
            break;
        }
        if (i == n && ns > level) {
            ns = level;
            return;
        }
    }
    for (int i = x; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (level > ll) {
                return;
            }
            if (z[i][j - 1] == 0 && z[i][j] == 0 && z[i][j + 1] == 0) {
                z[i][j] = 1;
                foo(i, j + 2, level + 1, ll);
                z[i][j] = 0;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int w, e;
        cin >> w >> e;
        z[w][e] = 1;
    }
    for (int i = 0; i < 4; i++) {
        foo(1, 1, 0, i);
        if (ns != 4) {
            cout << ns;
            return 0;
        }
    }
    if (ns == 4) {
        cout << -1;
    }
}