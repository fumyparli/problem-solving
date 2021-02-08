#include <bits/stdc++.h>
using namespace std;

map<string, int> h;
vector<pair<int, string>> v;
map<string, set<pair<int, int>>> m;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++) {
        h[genres[i]] += plays[i];
        m[genres[i]].insert({-plays[i], i});
    }
    for (auto &i : h) {
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end(), greater<>());
    for (auto &i : v) {
        int cnt = 0;
        for (auto &j : m[i.second]) {
            answer.push_back(j.second);
            cnt++;
            if (cnt == 2) break;
        }
    }
    return answer;
}