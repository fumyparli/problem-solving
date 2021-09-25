#include <bits/stdc++.h>
using namespace std;
using tdiii = tuple<double, int, int, int>;
vector<tdiii> boxers(1001);

vector<int> solution(vector<int> w, vector<string> h) {
    for (int i = 0; i < h.size(); i++) {
        int totalCnt = 0, winCnt = 0, heavyWinCnt = 0;
        for (int j = 0; j < h.size(); j++) {
            if (h[i][j] != 'N') {
                totalCnt++;
            }
            if (h[i][j] == 'W') {
                winCnt++;
                if (w[i] < w[j]) {
                    heavyWinCnt++;
                }
            }
        }
        double winRate = totalCnt ? (double)winCnt / totalCnt : 0;
        boxers[i] = {winRate, heavyWinCnt, w[i], -(i + 1)};
    }
    sort(boxers.begin(), boxers.end(), greater<tdiii>());
    vector<int> ans;
    for (int i = 0; i < w.size(); i++) {
        auto [q, w, e, r] = boxers[i];
        ans.push_back(-r);
    }
    return ans;
}