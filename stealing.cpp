#include <bits/stdc++.h>
using namespace std;
#define inf 1001
int d[1000001];
int solution(vector<int> money) {
    memset(d, -1, sizeof(d));
    int m_size = money.size();
    int min = inf;
    int min_idx = -1;
    for (int i = 0; i < m_size; i++) {
        if (min > money[i]) {
            min = money[i];
            min_idx = i;
        }
    }
    for (int i = 0; i < min_idx; i++) {
        money.push_back(money[i]);
    }
    money.erase(money.begin(), money.begin() + min_idx);
    money.push_back(money[0]);
    int check[2];
    d[0] = money[0];
    for (int i = 1; i <= m_size; i++) {
        if (d[i] < d[i - 2] + money[i]) {
            d[i] = d[i - 2] + money[i];
            if (i - 2 == 0)
                check[0] = 1;
            if (i == m_size)
                check[1] = 1;
        }
        if (d[i] < d[i - 1]) {
            d[i] = d[i - 1];
            if (i - 1 == 0)
                check[0] = 1;
        }
    }
    int cnt = 0;
    if (check[0] == 1) cnt++;
    if (check[1] == 1) cnt++;
    if (cnt == 2) d[m_size] -= money[0];
    return d[m_size];
}