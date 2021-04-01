#include <bits/stdc++.h>
using namespace std;

struct trie {
    struct node {
        int child[26];
        int valid;
        node() {
            memset(child, -1, sizeof(child));
            valid = 0;
        };
    };
    vector<node> tr;
    int init() {
        node new_node;
        tr.push_back(new_node);
        return (int)tr.size() - 1;
    }
    int root = init();
    void insert(int x, string& s, int i) {
        tr[x].valid++;
        if (i == s.size()) return;
        int c = s[i] - 'a';
        if (tr[x].child[c] == -1) tr[x].child[c] = init();
        int nx = tr[x].child[c];
        insert(nx, s, i + 1);
    }
    void insert(string& s) {
        insert(root, s, 0);
    }
    int find(int x, string& s, int i) {
        if (x == -1) return 0;
        if (tr[x].valid == 1 || i == s.size()) return i;
        int c = s[i] - 'a';
        int nx = tr[x].child[c];
        return find(nx, s, i + 1);
    }
    int find(string& s) {
        return find(root, s, 0);
    }
};

int solution(vector<string> words) {
    int ans = 0;
    trie tr;
    for (auto s : words) tr.insert(s);
    for (auto s : words) ans += tr.find(s);
    return ans;
}