#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int check[200001];
multimap<ll, int> ma;

int solution(vector<int> food_times, ll k) {
    ll cnt = 0;
    for (int i = 0; i < food_times.size(); i++) {
        ma.insert({food_times[i], i});
    }
    int modnum = -1;
    while (!ma.empty()) {
        auto iter = ma.begin();
        if (k < (iter->first - cnt) * (ll)ma.size()) {
            modnum = k % ma.size();
            break;
        } else {
            k -= (iter->first - cnt) * (ll)ma.size();
            check[iter->second] = 1;
            cnt = iter->first;
            ma.erase(iter);
        }
    }
    if (modnum == -1) return -1;
    for (int i = 0; i < food_times.size(); i++) {
        if (check[i] == 0) {
            if (modnum == 0) return i + 1;
            modnum--;
        }
    }
}