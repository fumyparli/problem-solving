#include <bits/stdc++.h>
using namespace std;

struct newnode {
    int x;
    int id;
    int left;
    int right;
};

newnode a[10001];
vector<vector<int>> answer(2);

struct info {
    int x;
    int y;
    int id;
};

void preorder(int x) {
    if (x == -1) return;
    answer[0].push_back(a[x].id);
    preorder(a[x].left);
    preorder(a[x].right);
}

void postorder(int x) {
    if (x == -1) return;
    postorder(a[x].left);
    postorder(a[x].right);
    answer[1].push_back(a[x].id);
}

int idx = 0;

void insert_node(int i, int x, int id) {
    if (a[i].id == -1) {
        a[i] = {x, id, -1, -1};
    } else if (x < a[i].x) {
        if (a[i].left == -1) a[i].left = ++idx;
        insert_node(a[i].left, x, id);
    } else {
        if (a[i].right == -1) a[i].right = ++idx;
        insert_node(a[i].right, x, id);
    }
}

bool cmp(const info &a, const info &b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

vector<info> node;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    memset(a, -1, sizeof(a));
    for (int i = 0; i < nodeinfo.size(); i++) {
        node.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1});
    }
    sort(node.begin(), node.end(), cmp);
    for (int i = 0; i < node.size(); i++) {
        insert_node(0, node[i].x, node[i].id);
    }
    preorder(0);
    postorder(0);
    return answer;
}