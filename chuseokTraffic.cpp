#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<pair<int, int>> t;

int solution(vector<string> lines) {
    int answer = 0;
    int idx = 0;
    for (auto &s : lines) {
        string s1, s2, s3;
        stringstream(s) >> s1 >> s2 >> s3;
        stringstream f(s2);
        int sum = 0;
        getline(f, s1, ':');
        sum += stoi(s1) * 3600 * 1000;

        getline(f, s1, ':');
        sum += stoi(s1) * 60 * 1000;

        getline(f, s1, '.');
        sum += stoi(s1) * 1000;

        getline(f, s1, ' ');
        sum += stoi(s1);

        int n = 0;
        stringstream k(s3);
        getline(k, s2, 's');
        n += stod(s2) * 1000;

        t.push_back({sum - n + 2, sum});
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) {
        int cnt = 0;
        int st = t[i].first;
        int ed = t[i].first + 1000;
        for (int j = 0; j < t.size(); j++) {
            int fi = t[j].first;
            int se = t[j].second;
            if (st <= fi && fi <= ed || st <= se && se <= ed || fi <= st && se >= ed) {
                cnt++;
            }
        }
        if (answer < cnt) answer = cnt;
        cnt = 0;
        st = t[i].second;
        ed = t[i].second + 1000;
        for (int j = 0; j < t.size(); j++) {
            int fi = t[j].first;
            int se = t[j].second;
            if (st <= fi && fi <= ed || st <= se && se <= ed || fi <= st && se >= ed) {
                cnt++;
            }
        }
        if (answer < cnt) answer = cnt;
    }
    return answer;
}