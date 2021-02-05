#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (true) {
        if (i == a.size() || j == b.size()) break;
        if (a[i] < b[j]) {
            answer++;
            i++;
        }
        j++;
    }
    return answer;
}