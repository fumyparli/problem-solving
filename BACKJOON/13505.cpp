#include <bits/stdc++.h>
using namespace std;

vector<string> a;

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
    void insert(int x, string& s, int i) {
        if (i == s.size()) {
            tr[x].valid = 1;
            return;
        }
        int c = s[i] - '0';
        if (tr[x].child[c] == -1) tr[x].child[c] = init();
        int nx = tr[x].child[c];
        insert(nx, s, i + 1);
    }
    void insert(string& s) {
        insert(root, s, 0);
    }
    string find(int x, string& s, int i, string& ans) {
        if (i == s.size()) return ans;
        int c = s[i] - '0';
        int nx = tr[x].child[c];
        if (nx == -1) {
            nx = tr[x].child[!c];
            ans += to_string(!c);
        } else {
            ans += to_string(c);
        }
        return find(nx, s, i + 1, ans);
    }
    string find(string& s) {
        string ans;
        return find(root, s, 0, ans);
    }
};

string make_binary(int x) {
    string s = "";
    while (true) {
        if (x == 0) break;
        s += to_string(x % 2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    string tmp = "";
    for (int i = 0; i < 32 - s.size(); i++) {
        tmp += '0';
    }
    return tmp + s;
}

string make_reverse(string s) {
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '1')
                    tmp += '0';
                else
                    tmp += '1';
            }
            break;
        } else {
            tmp += s[i];
        }
    }
    return tmp;
}

int get_int(string s) {
    int j = 0;
    int ret = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        ret += (s[i] - '0') * pow(2, j++);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    trie tr;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        string s = make_binary(k);
        a.push_back(s);
        tr.insert(s);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int n1 = get_int(a[i]);
        string s = make_reverse(a[i]);
        s = tr.find(s);
        int n2 = get_int(s);
        ans = max(ans, n1 ^ n2);
    }
    cout << ans;
}