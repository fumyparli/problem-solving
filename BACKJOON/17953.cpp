#include<iostream>
using namespace std;

int a[100001][11];
int d[100001][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				d[1][j] = a[1][j];
				continue;
			}
			int M_d = -1;
			d[i - 1][j] -= a[i][j] / 2;
			if (a[i][j] % 2 != 0) {
				d[i - 1][j]--;
			}
			for (int k = 1; k <= m; k++) {
				if (M_d < d[i - 1][k]) {
					M_d = d[i - 1][k];
				}
			}
			d[i - 1][j] += a[i][j] / 2;
			if (a[i][j] % 2 != 0) {
				d[i - 1][j]++;
			}
			d[i][j] = M_d + a[i][j];
		}
	}
	int ans = -1;
	for (int i = 1; i <= m; i++) {
		if (ans < d[n][i]) {
			ans = d[n][i];
		}
	}
	cout << ans;
}