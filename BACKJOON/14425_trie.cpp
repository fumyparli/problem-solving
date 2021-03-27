#include <bits/stdc++.h>
using namespace std;

struct trie {
    struct node {
        int child[26];
        bool valid;
        node() {
            memset(child, -1, sizeof(child));
            valid = false;
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
        if (i == s.size()) {
            tr[x].valid = 1;
            return;
        }
        int c = s[i] - 'a';
        if (tr[x].child[c] == -1) tr[x].child[c] = init();
        int nx = tr[x].child[c];
        insert(nx, s, i + 1);
    }
    void insert(string& s) {
        insert(root, s, 0);
    }
    bool find(int x, string& s, int i) {
        if (x == -1) return false;
        if (i == s.size()) return tr[x].valid;
        int c = s[i] - 'a';
        int nx = tr[x].child[c];
        return find(nx, s, i + 1);
    }
    bool find(string& s) {
        return find(root, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    trie tr;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tr.insert(s);
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        cin >> s;
        if (tr.find(s)) ans++;
    }
    cout << ans;
}