#include <bits/stdc++.h>
using namespace std;

struct ball {
    int no;
    int color;
    int cost;
};

bool cmp(ball &b1, ball &b2) {
    return b1.cost < b2.cost;
}

vector<ball> a;
int d[200001];
vector<vector<int>> color_d(200001);
vector<vector<int>> color_l(200001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q, w;
        cin >> q >> w;
        a.push_back({i, q, w});
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++) {
        color_d[a[i].color].push_back(a[i].cost);
        color_l[a[i].color].push_back(a[i].cost);
        d[i] = a[i].cost;
    }
    for (int i = 0; i <= n; i++) {
        sort(color_d[i].begin(), color_d[i].end());
        sort(color_l[i].begin(), color_l[i].end());
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < color_d[i].size(); j++) {
            if (j > 0)
                color_d[i][j] += color_d[i][j - 1];
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (i > 0)
            d[i] += d[i - 1];
    }
    vector<int> ans(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i].cost;
    }
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
        if (idx > 0) {
            ans[a[i].no] = d[idx - 1];
            int idx2 = lower_bound(color_l[a[i].color].begin(), color_l[a[i].color].end(), b[i]) - color_l[a[i].color].begin();
            if (idx2 > 0) {
                ans[a[i].no] -= color_d[a[i].color][idx2 - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}