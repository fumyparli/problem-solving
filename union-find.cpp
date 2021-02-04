#include <bits/stdc++.h>
using namespace std;

int parent[101];
int level[101];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    if (find(x) == find(y)) return;
    if (level[x] > level[y]) swap(x, y);
    parent[x] = y;
    if (level[x] == level[y]) level[y]++;
}

int main() {
    for (int i = 0; i < 101; i++) {
        level[i] = i;
        parent[i] = i;
    }
}