#include <vector>
using namespace std;

int d[100001][4];
int foo(int i, int j, vector<vector<int>> &a) {
    if (i == -1) return 0;
    if (d[i][j] != 0) {
        return d[i][j];
    }
    int max = 0;
    for (int k = 0; k < 4; k++) {
        int foo_max = 0;
        if (k != j) {
            foo_max = foo(i - 1, k, a);
            if (max < foo_max) {
                max = foo_max;
            }
        }
    }
    d[i][j] = max + a[i][j];
    return d[i][j];
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    for (int i = 0; i < 4; i++) {
        foo(land.size() - 1, i, land);
    }
    for (int i = 0; i < 4; i++) {
        if (answer < d[land.size() - 1][i])
            answer = d[land.size() - 1][i];
    }
    return answer;
}