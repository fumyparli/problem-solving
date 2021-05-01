#include <bits/stdc++.h>
using namespace std;
int l[7] = {6, 6, 5, 4, 3, 2, 1};
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int cnt = 0;
    int zerocnt = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) zerocnt++;
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                cnt++;
            }
        }
    }
    return {l[cnt + zerocnt], l[cnt]};
}