#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll, ll> p;

ll find(ll x) {
    if (!p[x]) {
        return x;
    }
    return p[x] = find(p[x]);
}

void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    p[x] = y;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (auto& r : room_number) {
        if (!p[r]) {
            answer.push_back(r);
            merge(r, r + 1);
        } else {
            ll tf = find(r);
            answer.push_back(tf);
            merge(tf, tf + 1);
        }
    }
    return answer;
}