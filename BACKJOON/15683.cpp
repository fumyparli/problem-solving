#include <bits/stdc++.h>
#define inf 987654321;
using namespace std;

struct node {
    int i, j, cctv;
};
vector<node> v;
int n, m, ans = inf;
int a[8][8];

void draw(int i, int j, int direction) {  //선택한 방향으로 그리는 함수
    if (direction == 0) {
        while (true) {
            i++;
            if (i >= n || a[i][j] == 6) {
                break;
            }
            if (a[i][j] == 0 || a[i][j] % 7 == 0) {
                a[i][j] += 7;
            }
        }
    } else if (direction == 1) {
        while (true) {
            j--;
            if (j < 0 || a[i][j] == 6) {
                break;
            }
            if (a[i][j] == 0 || a[i][j] % 7 == 0) {
                a[i][j] += 7;
            }
        }
    } else if (direction == 2) {
        while (true) {
            i--;
            if (i < 0 || a[i][j] == 6) {
                break;
            }
            if (a[i][j] == 0 || a[i][j] % 7 == 0) {
                a[i][j] += 7;
            }
        }
    } else if (direction == 3) {
        while (true) {
            j++;
            if (j >= m || a[i][j] == 6) {
                break;
            }
            if (a[i][j] == 0 || a[i][j] % 7 == 0) {
                a[i][j] += 7;
            }
        }
    }
}

void undraw(int i, int j, int direction) {  //선택한 방향으로 삭제하는 함수
    if (direction == 0) {
        while (true) {
            i++;
            if (i >= n || a[i][j] == 6) {
                break;
            }
            a[i][j] -= 7;
        }
    } else if (direction == 1) {
        while (true) {
            j--;
            if (j < 0 || a[i][j] == 6) {
                break;
            }
            a[i][j] -= 7;
        }
    } else if (direction == 2) {
        while (true) {
            i--;
            if (i < 0 || a[i][j] == 6) {
                break;
            }
            a[i][j] -= 7;
        }
    } else if (direction == 3) {
        while (true) {
            j++;
            if (j >= m || a[i][j] == 6) {
                break;
            }
            a[i][j] -= 7;
        }
    }
}

void foo(int i, int j, int cctv, int level, int direction) {
    //그리는 부분
    if (cctv == 1) {
        draw(i, j, direction);
    } else if (cctv == 2) {
        draw(i, j, direction);
        draw(i, j, (direction + 2) % 4);
    } else if (cctv == 3) {
        draw(i, j, direction);
        draw(i, j, (direction + 1) % 4);
    } else if (cctv == 4) {
        draw(i, j, direction);
        draw(i, j, (direction + 1) % 4);
        draw(i, j, (direction + 2) % 4);
    } else if (cctv == 5) {
        draw(i, j, direction);
        draw(i, j, (direction + 1) % 4);
        draw(i, j, (direction + 2) % 4);
        draw(i, j, (direction + 3) % 4);
    }

    //탈출 및 ans 저장
    if (level == v.size() - 1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    cnt++;
                }
            }
        }

        if (cnt < ans) {
            ans = cnt;
        }
        return;
    }

    //다음 백트래킹 들어가는 부분
    for (int k = 0; k < 4; k++) {  // 네 방향에 대해
        foo(v[level + 1].i, v[level + 1].j, v[level + 1].cctv, level + 1, k);
    }

    //삭제하는 부분
    if (cctv == 1) {
        undraw(i, j, direction);
    } else if (cctv == 2) {
        undraw(i, j, direction);
        undraw(i, j, (direction + 2) % 4);
    } else if (cctv == 3) {
        undraw(i, j, direction);
        undraw(i, j, (direction + 1) % 4);
    } else if (cctv == 4) {
        undraw(i, j, direction);
        undraw(i, j, (direction + 1) % 4);
        undraw(i, j, (direction + 2) % 4);
    } else if (cctv == 5) {
        undraw(i, j, direction);
        undraw(i, j, (direction + 1) % 4);
        undraw(i, j, (direction + 2) % 4);
        undraw(i, j, (direction + 3) % 4);
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
    v.push_back({0, 0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0 && a[i][j] != 6) {
                v.push_back({i, j, a[i][j]});
            }
        }
    }
    v.push_back({0, 0, 0});
    foo(v[0].i, v[0].j, v[0].cctv, 0, 0);
    cout << ans;
}