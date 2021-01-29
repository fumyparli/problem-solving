#include <bits/stdc++.h>
using namespace std;
int limit;
string result;
char h[6] = {17, 18, 19, 20, 21, 22};
string makeN(int k, int n) {
    string s;
    while (true) {
        int tmp = k % n;
        if (tmp >= 10) {
            tmp -= 10;
            tmp = h[tmp];
        }
        s += (tmp + '0');
        k /= n;
        if (k == 0) {
            break;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    limit = m * t;
    for (int i = 0; i < limit; i++) {
        string tmp = makeN(i, n);
        result += tmp;
    }
    for (int i = 0; i < t; i++) {
        answer += result[p - 1 + m * i];
    }
    return answer;
}