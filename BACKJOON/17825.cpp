#include <bits/stdc++.h>
using namespace std;

struct A {
    int idx, black, point, blue = -1;
};
A a[100] = {
    {0, 1, 0},
    {1, 2, 2},
    {2, 3, 4},
    {3, 4, 6},
    {4, 5, 8},
    {5, 6, 10, 21},  //5
    {6, 7, 12},
    {7, 8, 14},
    {8, 9, 16},
    {9, 10, 18},
    {10, 11, 20, 25},  //10
    {11, 12, 22},
    {12, 13, 24},
    {13, 14, 26},
    {14, 15, 28},
    {15, 16, 30, 27},  //15
    {16, 17, 32},
    {17, 18, 34},
    {18, 19, 36},
    {19, 20, 38},
    {20, 32, 40},  //20
    {21, 22, 13},
    {22, 23, 16},
    {23, 24, 19},
    {24, 30, 25},  // 24: 25점 짜리 가운데꺼
    {25, 26, 22},
    {26, 24, 24},
    {27, 28, 28},
    {28, 29, 27},
    {29, 24, 26},
    {30, 31, 30},
    {31, 20, 35},
    {32, -1, 0},  // 32: 도착
};
int pos[4];  // 말의 위치
int dice[10];
vector<int> v;
int ans;

int go(int i, int dice, int cnt) {
    if (pos[i] == 32) {
        return 0;
    }
    if (cnt == 0) {
        for (int j = 0; j < 4; j++) {
            if (i != j && pos[i] == pos[j]) {
                return -1;
            }
        }
        return a[pos[i]].point;
    }
    if (dice == cnt && a[pos[i]].blue != -1) {
        pos[i] = a[pos[i]].blue;
        return go(i, dice, cnt - 1);
    }
    pos[i] = a[pos[i]].black;
    return go(i, dice, cnt - 1);
}
int ccc;
void foo() {
    if (v.size() == 10) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            pos[i] = 0;
        }
        for (int i = 0; i < 10; i++) {
            if (pos[v[i]] != 32) {
                int k = go(v[i], dice[i], dice[i]);
                if (k == -1) {
                    return;
                } else {
                    sum += k;
                }
            }
        }
        ans = max(sum, ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        v.push_back(i);
        foo();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }
    foo();
    cout << ans;
}