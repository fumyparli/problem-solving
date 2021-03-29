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
        if (i == s.size()) {
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
    int find(int x, string& s, int i) {
        if (x == -1) return 0;
        if (i == s.size()) return tr[x].valid;
        int c = s[i] - 'a';
        int nx = tr[x].child[c];
        return find(nx, s, i + 1);
    }
    int find(string& s) {
        return find(root, s, 0);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    trie tr[10001];
    trie rtr[10001];
    for (auto& s : words) {
        int s_size = s.size();
        tr[s_size].insert(s);
        reverse(s.begin(), s.end());
        rtr[s_size].insert(s);
    }
    for (auto& s : queries) {
        int s_size = s.size();
        if (s[0] == '?') {
            reverse(s.begin(), s.end());
            stringstream ss(s);
            getline(ss, s, '?');
            answer.push_back(rtr[s_size].find(s));
        } else {
            stringstream ss(s);
            getline(ss, s, '?');
            answer.push_back(tr[s_size].find(s));
        }
    }
    return answer;
}