#include <bits/stdc++.h>
using namespace std;
#define inf 987654321

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> v(201);
    int d[101][201];

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 201; j++) {
            d[i][j] = inf;
        }
    }
    d[0][gps_log[0]] = 0;
    for (int i = 0; i < edge_list.size(); i++) {
        v[edge_list[i][0]].push_back(edge_list[i][1]);
        v[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = min(d[i - 1][j], d[i][j]);
            for (int l = 0; l < v[j].size(); l++) {
                d[i][j] = min(d[i - 1][v[j][l]], d[i][j]);
            }
            if (gps_log[i] != j) d[i][j]++;
        }
    }
    if (d[k - 1][gps_log[k - 1]] >= inf) return -1;
    return d[k - 1][gps_log[k - 1]];
}