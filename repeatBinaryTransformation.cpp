#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string makeBinary(int k) {
    string s = "";
    while (true) {
        if (k == 0) break;
        if (k % 2 == 1) {
            s += '1';
        } else {
            s += '0';
        }
        k /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (true) {
        string k = "";
        if (s == "1") {
            break;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                k += '1';
            } else {
                answer[1]++;
            }
        }
        s = makeBinary(k.size());
        answer[0]++;
    }
    return answer;
}