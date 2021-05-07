#include <bits/stdc++.h>
using namespace std;

int check[100001];

bool cmp(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> a;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            vector<int> tmp;
            string k = "";
            for (int j = i + 1; j < s.size() - 1; j++) {
                if (s[j] == '}') {
                    tmp.push_back(stoi(k));
                    k = "";
                    i = j + 1;
                    break;
                } else if (s[j] == ',') {
                    tmp.push_back(stoi(k));
                    k = "";
                } else {
                    k += s[j];
                }
            }
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end(), cmp);
    for (auto ai : a) {
        for (auto aij : ai) {
            if (check[aij] == 0) {
                check[aij] = 1;
                answer.push_back(aij);
            }
        }
    }
    return answer;
}