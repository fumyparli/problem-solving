#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[11][11], aa[11][11];
int ans;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
map<pair<int, int>, deque<int>> t;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    ans += m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &aa[i][j]);
            a[i][j] = 5;
        }
    }
    deque<int> dq;
    for (int i = 0; i < m; i++) {
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        x--;
        y--;
        dq.push_back(age);
        t.insert({{x, y}, dq});
        dq.pop_back();
    }
    dq.push_back(1);
    for (int i = 0; i < k; i++) {
        vector<pair<pair<int, int>, int>> dead_tree;
        vector<pair<int, int>> will_born;
        for (auto iter = t.begin(); iter != t.end(); iter++) {
            for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();) {
                int x = iter->first.first;
                int y = iter->first.second;
                if (a[x][y] >= *iter2) {
                    a[x][y] -= *iter2;
                    *iter2 += 1;
                    if ((*iter2) % 5 == 0) {
                        will_born.push_back({x, y});
                    }
                    iter2++;
                } else {
                    dead_tree.push_back({{x, y}, iter->second.back() / 2});
                    iter->second.pop_back();
                    ans--;
                }
            }
        }
        for (int j = 0; j < dead_tree.size(); j++) {
            a[dead_tree[j].first.first][dead_tree[j].first.second] += dead_tree[j].second;
        }
        for (int j = 0; j < will_born.size(); j++) {
            for (int k = 0; k < 8; k++) {
                int x = will_born[j].first + dx[k];
                int y = will_born[j].second + dy[k];
                if (0 <= x && 0 <= y && x < n && y < n) {
                    auto f = t.find({x, y});
                    if (f != t.end()) {
                        f->second.push_front(1);
                    } else {
                        t.insert({{x, y}, dq});
                    }
                    ans++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[j][k] += aa[j][k];
            }
        }
    }
    printf("%d", ans);
}