#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5, 6}, {3, 4, 7}, {4, 7}, {5, 6}};
int d[100001][8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    d[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < a[j].size(); k++)
                d[i][j] = (d[i][j] + d[i - 1][a[j][k]]) % 1000000007;
    cout << d[n][0];
}