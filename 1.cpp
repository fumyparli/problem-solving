#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<bool> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++) {
        if (b[i])
            answer += a[i];
        else
            answer -= a[i];
    }
    return answer;
}