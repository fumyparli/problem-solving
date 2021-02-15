#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int answer = 0;
    queue<int> q;
    sort(timetable.begin(), timetable.end());
    for (int i = 0; i < timetable.size(); i++) {
        string h = "", m = "";
        h += timetable[i][0];
        h += timetable[i][1];
        m += timetable[i][3];
        m += timetable[i][4];
        q.push(stoi(h) * 60 + stoi(m));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = 987654321;
            if (q.front() <= 9 * 60 + i * t) {
                p = q.front();
                q.pop();
            }
            if (i == n - 1 && j == m - 1) {
                answer = min(p - 1, 9 * 60 + i * t);
                break;
            }
            if (q.empty()) {
                answer = 9 * 60 + (n - 1) * t;
                break;
            }
        }
    }
    string t1 = to_string(answer / 60);
    string t2 = to_string(answer % 60);
    if (t1.size() == 1) {
        string tmp = t1;
        t1 = "";
        t1 += '0';
        t1 += tmp;
    }
    t1 += ':';
    if (t2.size() == 1) {
        string tmp = t2;
        t2 = "";
        t2 += '0';
        t2 += tmp;
    }
    return t1 + t2;
}
