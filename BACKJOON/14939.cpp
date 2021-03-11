#include <bits/stdc++.h>
using namespace std;

int a[11][11];
int b[11][11];
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};

void convert(int i, int j) {
    for (int k = 0; k < 5; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
            a[nx][ny] = !a[nx][ny];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == 'O')
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    }
    int ans = 1000;
    for (int k = 0; k < 1024; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = b[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (k & (1 << i)) {
                convert(0, i);
                cnt++;
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (a[i - 1][j] == 1) {
                    cnt++;
                    convert(i, j);
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (a[i][j] == 1) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            ans = min(ans, cnt);
        }
    }
    cout << ans;
}