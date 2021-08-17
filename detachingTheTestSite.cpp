#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> num;

int foo(int x, int &cnt, int &mid) {
    if (x == -1) return 0;
    int t1 = foo(a[x][0], cnt, mid), t2 = foo(a[x][1], cnt, mid);
    int sum = num[x] + t1 + t2;
    int maxv = max(t1, t2), minv = min(t1, t2);
    if (maxv != 0 && sum > mid) {
        sum -= maxv;
        cnt++;
    }
    if (minv != 0 && sum > mid) {
        sum -= minv;
        cnt++;
    }
    return sum;
}

int parent[10001];

int solution(int k, vector<int> num2, vector<vector<int>> links) {
    a = links;
    num = num2;
    int st = 0, ed = 0;
    for (auto num : num) {
        st = max(st, num);
        ed += num;
    }
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < links.size(); i++) {
        parent[links[i][0]] = i;
        parent[links[i][1]] = i;
    }
    int root;
    for (int i = 0; i < links.size(); i++) {
        if (parent[i] == -1) root = i;
    }
    while (st < ed) {
        int mid = (st + ed) / 2;
        int cnt = 0;
        foo(root, cnt, mid);
        if (cnt + 1 <= k) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    return ed;
}