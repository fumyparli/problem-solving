#include <bits/stdc++.h>
using namespace std;

vector<string> a;
vector<string> b;
vector<string> ans;
int check[8];
int answer;
set<vector<string>> s_check;

int judge(vector<string> k) {
    int flag = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i].size() != b[i].size()) {
            flag = 1;
            break;
        }
        for (int j = 0; j < k[i].size(); j++) {
            if (!(k[i][j] == b[i][j] || b[i][j] == '*')) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    if (flag == 0) {
        sort(k.begin(), k.end());
        s_check.insert(k);
        return 1;
    } else
        return 0;
}

void foo() {
    if (ans.size() == b.size()) {
        vector<string> tmp = ans;
        sort(tmp.begin(), tmp.end());
        if (s_check.find(tmp) == s_check.end() && judge(ans)) {
            answer++;
        }
        return;
    }
    for (int i = 0; i < a.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            ans.push_back(a[i]);
            foo();
            ans.pop_back();
            check[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    a = user_id;
    b = banned_id;
    foo();
    return answer;
}