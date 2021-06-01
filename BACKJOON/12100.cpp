#include <iostream>
using namespace std;

int a[20][20];
int d[20][20][6];
int ans = -1;
int n;

void left_c(int x) {  //d[][][x]에 대해 이동하기
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (d[i][j][x] != 0 && d[i][j - 1][x] == 0) {
                int tmp = d[i][j][x];
                d[i][j][x] = 0;
                int idx = j;
                while (true) {
                    idx--;
                    if (idx < 0 || idx >= n || d[i][idx][x] != 0) {
                        break;
                    }
                }
                d[i][++idx][x] = tmp;
            }
        }
    }
}

void right_c(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (d[i][j][x] != 0 && d[i][j + 1][x] == 0) {
                int tmp = d[i][j][x];
                d[i][j][x] = 0;
                int idx = j;
                while (true) {
                    idx++;
                    if (idx < 0 || idx >= n || d[i][idx][x] != 0) {
                        break;
                    }
                }
                d[i][--idx][x] = tmp;
            }
        }
    }
}

void up_c(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (d[j][i][x] != 0 && d[j - 1][i][x] == 0) {
                int tmp = d[j][i][x];
                d[j][i][x] = 0;
                int idx = j;
                while (true) {
                    idx--;
                    if (idx < 0 || idx >= n || d[idx][i][x] != 0) {
                        break;
                    }
                }
                d[++idx][i][x] = tmp;
            }
        }
    }
}

void down_c(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (d[j][i][x] != 0 && d[j + 1][i][x] == 0) {
                int tmp = d[j][i][x];
                d[j][i][x] = 0;
                int idx = j;
                while (true) {
                    idx++;
                    if (idx < 0 || idx >= n || d[idx][i][x] != 0) {
                        break;
                    }
                }
                d[--idx][i][x] = tmp;
            }
        }
    }
}

void jud_left(int x) {             //판단
    for (int i = 0; i < n; i++) {  //복사
        for (int j = 0; j < n; j++) {
            d[i][j][x + 1] = d[i][j][x];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            left_c(x + 1);
            if (d[i][j][x + 1] == d[i][j - 1][x + 1]) {
                d[i][j - 1][x + 1] += d[i][j][x + 1];
                d[i][j][x + 1] = 0;
            }
        }
    }
    left_c(x + 1);
}

void jud_right(int x) {  //판단
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j][x + 1] = d[i][j][x];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            right_c(x + 1);
            if (d[i][j][x + 1] == d[i][j + 1][x + 1]) {
                d[i][j + 1][x + 1] += d[i][j][x + 1];
                d[i][j][x + 1] = 0;
            }
        }
    }
    right_c(x + 1);
}

void jud_up(int x) {  //판단
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j][x + 1] = d[i][j][x];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            up_c(x + 1);
            if (d[j][i][x + 1] == d[j - 1][i][x + 1]) {
                d[j - 1][i][x + 1] += d[j][i][x + 1];
                d[j][i][x + 1] = 0;
            }
        }
    }
    up_c(x + 1);
}

void jud_down(int x) {  //판단
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j][x + 1] = d[i][j][x];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            down_c(x + 1);
            if (d[j][i][x + 1] == d[j + 1][i][x + 1]) {
                d[j + 1][i][x + 1] += d[j][i][x + 1];
                d[j][i][x + 1] = 0;
            }
        }
    }
    down_c(x + 1);
}

void foo(int level) {  //전체백트래킹
    if (level == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans < d[i][j][level]) {
                    ans = d[i][j][level];
                }
            }
        }
        return;
    }
    jud_left(level);
    foo(level + 1);

    jud_right(level);
    foo(level + 1);

    jud_up(level);
    foo(level + 1);

    jud_down(level);
    foo(level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j][0];
        }
    }
    foo(0);
    cout << ans;
}