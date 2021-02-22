#include <bits/stdc++.h>
using namespace std;

long long d[360000];

int get_int(string s) {
    int sum = 0, cnt = 2;
    stringstream f(s);
    while (getline(f, s, ':')) {
        sum += stoi(s) * pow(60, cnt--);
    }
    return sum;
}

vector<pair<int, int>> a;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playtime = get_int(play_time.substr(0, 8));
    int adv = get_int(adv_time.substr(0, 8));

    for (int i = 0; i < logs.size(); i++) {
        int log1 = get_int(logs[i].substr(0, 8));
        int log2 = get_int(logs[i].substr(9, 8));
        a.push_back({log1, 0});
        a.push_back({log2, 1});
    }
    sort(a.begin(), a.end());
    int a_size = a.size();
    int cnt = 1;
    for (int i = 0; i < a_size - 1; i++) {
        for (int j = a[i].first; j < a[i + 1].first; j++) {
            d[j] = cnt;
        }
        if (a[i + 1].second == 0)
            cnt++;
        else
            cnt--;
    }
    long long sum = 0;
    for (int i = 0; i <= playtime; i++) {
        sum += d[i];
        d[i] = sum;
    }
    long long ans = 0;
    int ans_time = 0;
    for (int i = adv - 1; i <= playtime; i++) {
        if (d[i] - d[i - adv] > ans) {
            ans = d[i] - d[i - adv];
            ans_time = i - adv + 1;
        }
    }
    string tmp = to_string(ans_time / 3600);
    if (tmp.size() == 1) answer += '0';
    answer += tmp;
    answer += ':';
    tmp = to_string(ans_time % 3600 / 60);
    if (tmp.size() == 1) answer += '0';
    answer += tmp;
    answer += ':';
    tmp = to_string(ans_time % 60);
    if (tmp.size() == 1) answer += '0';
    answer += tmp;
    return answer;
}