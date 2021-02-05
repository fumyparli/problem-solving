#include <bits/stdc++.h>
using namespace std;
#define inf 987654321
int check[51];
int answer = inf;
string tar;

int can_it_change(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) cnt++;
    }
    if (cnt == s1.size() - 1) return 1;
    return 0;
}

void dfs(int x, vector<string> &words, int level) {
    if (words[x] == tar && answer > level) {
        answer = level;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (check[i] == 0 && can_it_change(words[x], words[i])) {
            check[i] = 1;
            dfs(i, words, level + 1);
            check[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    tar = target;
    dfs(words.size() - 1, words, 0);
    if (answer == inf) return 0;
    return answer;
}