#include <bits/stdc++.h>
using namespace std;
using tiiiiii = tuple<int, int, int, int, int, int>;
vector<tiiiiii> fires;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        fires.push_back({x - 1, y - 1, m, s, d, 0});
    }
    while (k--) {
        if (fires.size() == 0) break;
        for (auto &fire : fires) {
            auto &[x, y, m, s, d, o] = fire;
            x = (n + (x + dx[d] * s)) % n;
            y = (n + (y + dy[d] * s)) % n;
        }
        sort(fires.begin(), fires.end());
        vector<tiiiiii> tmp = {fires[0]};
        vector<tiiiiii> fires2;
        for (int i = 1; i <= fires.size(); i++) {
            auto &[x1, y1, m1, s1, d1, o1] = fires[i];
            auto &[x2, y2, m2, s2, d2, o2] = tmp[0];
            if (i != fires.size() && x1 == x2 && y1 == y2) {
                tmp.push_back(fires[i]);
            } else {
                int sameDir = 0, wSum = 0, sSum = 0;
                for (int j = 0; j < tmp.size(); j++) {
                    auto &[x, y, m, s, d, o] = tmp[j];
                    wSum += m;
                    sSum += s;
                    sameDir += (d % 2);
                }
                if (tmp.size() > 1) {
                    if (sameDir == 0 || sameDir == tmp.size()) {
                        sameDir = -1;
                    }
                    wSum /= 5;
                    sSum /= tmp.size();
                    o2 = 1;
                }
                if (sameDir != -1) sameDir = d2;
                fires2.push_back({x2, y2, wSum, sSum, sameDir, o2});
                tmp.clear();
                tmp.push_back(fires[i]);
            }
        }
        fires.clear();
        for (auto fire2 : fires2) {
            auto &[x, y, m, s, d, o] = fire2;
            if (m == 0) continue;
            if (o == 1) {
                if (d == -1) {
                    for (int k = 0; k < 8; k += 2) {
                        fires.push_back({x, y, m, s, k, 0});
                    }
                } else {
                    for (int k = 1; k < 8; k += 2) {
                        fires.push_back({x, y, m, s, k, 0});
                    }
                }
            } else {
                fires.push_back({x, y, m, s, d, 0});
            }
        }
    }
    int mSum = 0;
    for (auto fire : fires) {
        auto [x, y, m, s, d, o] = fire;
        mSum += m;
    }
    cout << mSum;
}