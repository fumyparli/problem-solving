#include <bits/stdc++.h>
using namespace std;

struct trie {
    struct node {
        int child[2];
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
    void insert(int x, int n, int i) {
        if (i == -1) {
            tr[x].valid = 1;
            return;
        }
        int c = (n >> i) & 1;
        if (tr[x].child[c] == -1) tr[x].child[c] = init();
        int nx = tr[x].child[c];
        insert(nx, n, i - 1);
    }
    void insert(int n) {
        insert(root, n, 31);
    }
    int find(int x, int n, int i) {
        if (i == -1) return 0;
        int c = !((n >> i) & 1);
        if (tr[x].child[c] == -1) c = !c;
        int nx = tr[x].child[c];
        return (c << i) | find(nx, n, i - 1);
    }
    int find(int n) {
        return find(root, n, 31);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        trie tr;
        tr.insert(0);
        int ans = 0;
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            xor_sum ^= k;
            tr.insert(xor_sum);
            ans = max(ans, xor_sum ^ tr.find(xor_sum));
        }
        cout << ans << '\n';
    }
}