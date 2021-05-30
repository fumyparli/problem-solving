#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int a[4][8];
int ans;
int check[4];

void rot(int g, int d) {
    if (d == 1) {
        int tmp = a[g][7];
        for (int i = 7; i > 0; i--) {
            a[g][i] = a[g][i - 1];
        }
        a[g][0] = tmp;
    } else {
        int tmp = a[g][0];
        for (int i = 0; i < 7; i++) {
            a[g][i] = a[g][i + 1];
        }
        a[g][7] = tmp;
    }
}

void foo(int g, int d) {
    /*cout << '\n';
	cout << g << "번돌림 " << d << "방향 " << '\n';
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}*/
    int right = a[g][6];
    int left = a[g][2];
    if (check[g] == 0) {
        check[g] = 1;
        rot(g, d);
        if (0 <= g - 1) {
            if (a[g - 1][2] != right) {
                foo(g - 1, -d);
            }
        }
        if (g + 1 <= 3) {
            if (a[g + 1][6] != left) {
                foo(g + 1, -d);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "";
    for (int i = 0; i < 4; i++) {
        string ss;
        cin >> ss;
        s += ss;
    }
    for (int i = 0; i < s.size(); i++) {
        a[i / 8][i % 8] = s[i] - '0';
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, d;
        cin >> n >> d;
        memset(check, 0, sizeof(check));
        foo(n - 1, d);
    }
    for (int i = 0; i < 4; i++) {
        if (a[i][0] == 1) {
            ans += (int)pow(2, i);
        }
    }
    cout << ans;
}