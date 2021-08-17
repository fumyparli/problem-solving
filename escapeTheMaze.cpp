#include <bits/stdc++.h>
using namespace std;

int check[1001][1025];
int tidx[1001];
vector<vector<pair<int, int>>> a(1001);
vector<vector<pair<int, int>>> ra(1001);

bool check_trap(int x, int trap_bit) {
    if (tidx[x] == -1) return false;
    int bit = 1;
    for (int i = 0; i < tidx[x]; i++) {
        bit = bit << 1;
    }
    return trap_bit & bit;
}

int get_ntrap_bit(int nx, int trap_bit) {
    if (tidx[nx] == -1) return trap_bit;
    int bit = 1;
    for (int i = 0; i < tidx[nx]; i++) {
        bit = bit << 1;
    }
    trap_bit ^= bit;
    return trap_bit;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    for (int i = 0; i < roads.size(); i++) {
        int q = roads[i][0], w = roads[i][1], e = roads[i][2];
        a[q].push_back({w, e});
        ra[w].push_back({q, e});
    }
    int idx = 0;
    memset(tidx, -1, sizeof(tidx));
    for (int i = 0; i < traps.size(); i++) {
        tidx[traps[i]] = idx++;
    }
    memset(check, -1, sizeof(check));
    queue<pair<int, int>> q;
    q.push({start, 0});
    check[start][0] = 0;
    while (!q.empty()) {
        auto [x, trap_bit] = q.front();
        q.pop();
        for (auto nr : ra[x]) {
            auto [nx, d] = nr;
            if (!(check_trap(x, trap_bit) ^ check_trap(nx, trap_bit))) continue;

            int ntrap_bit = get_ntrap_bit(nx, trap_bit);
            if (check[nx][ntrap_bit] == -1 || check[nx][ntrap_bit] > check[x][trap_bit] + d) {
                check[nx][ntrap_bit] = check[x][trap_bit] + d;
                q.push({nx, ntrap_bit});
            }
        }
        for (auto nr : a[x]) {
            auto [nx, d] = nr;
            if (check_trap(x, trap_bit) ^ check_trap(nx, trap_bit)) continue;

            int ntrap_bit = get_ntrap_bit(nx, trap_bit);
            if (check[nx][ntrap_bit] == -1 || check[nx][ntrap_bit] > check[x][trap_bit] + d) {
                check[nx][ntrap_bit] = check[x][trap_bit] + d;
                q.push({nx, ntrap_bit});
            }
        }
    }
    int answer = 2147483647;
    for (int i = 0; i < 1024; i++) {
        if (check[end][i] != -1) {
            answer = min(answer, check[end][i]);
        }
    }
    return answer;
}