#include <bits/stdc++.h>
using namespace std;

int check[500001];

int solution(vector<int> b) {
    int answer = 0;
    vector<int> a;
    int tmp = -1;
    int cnt = 0;
    int max_idx = -1;
    int max = -1;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == tmp) {
            cnt++;
        } else {
            tmp = b[i];
            cnt = 0;
        }
        if (cnt < 2) a.push_back(b[i]);
    }
    if (a.size() != 0 && a[0] == a[1]) a.erase(a.begin());
    if (a.size() != 0 && a[a.size() - 1] == a[a.size() - 2]) a.erase(a.end() - 1);

    for (auto& i : a) {
        check[i]++;
        if (max < check[i]) {
            max = check[i];
            max_idx = i;
        }
    }

    memset(check, 0, sizeof(check));
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == max_idx && check[i] == 0) {
            if (i > 0 && check[i - 1] == 0 && a[i - 1] != a[i]) {
                check[i] = 1;
                check[i - 1] = 1;
                answer += 2;
            } else if (i < a.size() - 1 && check[i + 1] == 0 && a[i] != a[i + 1]) {
                check[i] = 1;
                check[i + 1] = 1;
                answer += 2;
            }
        }
    }
    return answer;
}