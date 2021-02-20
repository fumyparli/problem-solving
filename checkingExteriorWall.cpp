#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000

int n, w_size;
vector<int> ans;
vector<int> dist;
vector<int> weak;
int check[8];
int answer = inf;

void foo() {
    if (ans.size() == dist.size()) {
        for (int l = 0; l < w_size; l++) {
            int k = 0;
            int i = l;
            int j = i;
            int flag = 0;
            while (true) {
                int tmp = weak[j] - weak[i];
                if (k == ans.size() && j < w_size + l) {
                    flag = 1;
                    break;
                }
                if (j == w_size + l) {
                    tmp = weak[j - 1] - weak[i];
                    if (tmp <= ans[k]) {
                        k++;
                        break;
                    }
                }
                if (tmp <= ans[k]) {
                    j++;
                } else {
                    k++;
                    i = j;
                }
            }
            if (flag == 0 && answer > k) answer = k;
        }
        return;
    }

    for (int i = 0; i < dist.size(); i++) {
        if (check[i] == 0) {
            ans.push_back(dist[i]);
            check[i] = 1;
            foo();
            check[i] = 0;
            ans.pop_back();
        }
    }
}

int solution(int nn, vector<int> w, vector<int> d) {
    n = nn;
    dist = d;
    w_size = w.size();
    weak = w;
    for (int i = 0; i < w.size(); i++) {
        weak.push_back(w[i] + n);
    };
    foo();
    if (answer == inf) return -1;
    return answer;
}