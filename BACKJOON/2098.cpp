#include <algorithm>
#include <cstring>
#include <iostream>
#define inf 1000000000
using namespace std;

int n;
int w[16][16];
int d[16][1 << 16];

int tsp(int st, int en) {
    if (en == ((1 << n) - 1)) {  //모두 방문 했으면
        if (w[st][0]) {          // 갈 길이 있으면
            return w[st][0];
        }
    }
    int& ret = d[st][en];
    if (ret) {
        return ret;
    }
    ret = inf;
    for (int i = 0; i < n; i++) {
        if (!(en & (1 << i)) && w[st][i]) {
            ret = min(ret, w[st][i] + tsp(i, en | (1 << i)));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    cout << tsp(0, 1);
}