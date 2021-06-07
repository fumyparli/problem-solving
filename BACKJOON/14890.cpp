#include <bits/stdc++.h>
using namespace std;

int n, L;
int a[100][100];
bool c[100];
int ans;

int main() {
    scanf("%d %d", &n, &L);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int flag = 0;
        memset(c, 0, sizeof(c));
        for (int j = 0; j < n; j++) {
            int is_ok = 0;
            if (j == n - 1) {
                ans++;
            }
            if (a[i][j] - a[i][j + 1] == -1) {
                if (cnt >= L && j - L + 1 >= 0) {
                    for (int k = j - L + 1; k <= j; k++) {
                        if (c[k] == 1) {
                            flag = 1;
                            break;
                        }
                        c[k] = 1;
                    }
                } else {
                    flag = 1;
                }
            } else if (a[i][j] - a[i][j + 1] == 1) {
                cnt = 1;
                for (int k = j + 1; k < n; k++) {
                    if (cnt >= L) {
                        for (int l = k - L + 1; l <= k; l++) {
                            if (c[l] == 1) {
                                flag = 1;
                                break;
                            }
                            c[l] = 1;
                        }
                        if (flag != 1) {
                            is_ok = 1;
                        }
                    }
                    if (is_ok == 1) {
                        j = k - 1;
                        cnt = 1;
                        break;
                    }
                    if (a[i][k] - a[i][k + 1] == 0) {
                        cnt++;
                    } else {
                        flag = 1;
                    }
                    if (flag == 1) {
                        break;
                    }
                }
            } else if (a[i][j] - a[i][j + 1] == 0 && is_ok == 0) {
                cnt++;
            } else {
                flag = 1;
            }
            if (flag == 1) {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int flag = 0;
        memset(c, 0, sizeof(c));
        for (int j = 0; j < n; j++) {
            int is_ok = 0;
            if (j == n - 1) {
                ans++;
            }
            if (a[j][i] - a[j + 1][i] == -1) {
                if (cnt >= L && j - L + 1 >= 0) {
                    for (int k = j - L + 1; k <= j; k++) {
                        if (c[k] == 1) {
                            flag = 1;
                            break;
                        }
                        c[k] = 1;
                    }
                } else {
                    flag = 1;
                }
            } else if (a[j][i] - a[j + 1][i] == 1) {
                cnt = 1;
                for (int k = j + 1; k < n; k++) {
                    if (cnt >= L) {
                        for (int l = k - L + 1; l <= k; l++) {
                            if (c[l] == 1) {
                                flag = 1;
                                break;
                            }
                            c[l] = 1;
                        }
                        if (flag != 1) {
                            is_ok = 1;
                        }
                    }
                    if (is_ok == 1) {
                        j = k - 1;
                        cnt = 1;
                        break;
                    }
                    if (a[k][i] - a[k + 1][i] == 0) {
                        cnt++;
                    } else {
                        flag = 1;
                    }
                    if (flag == 1) {
                        break;
                    }
                }
            } else if (a[j][i] - a[j + 1][i] == 0 && is_ok == 0) {
                cnt++;
            } else {
                flag = 1;
            }
            if (flag == 1) {
                break;
            }
        }
    }
    printf("%d", ans);
}