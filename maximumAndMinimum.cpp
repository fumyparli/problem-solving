#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    s += ' ';
    string answer = "";
    string tmp = "";
    int min = 2147483647;
    int max = -2147483648;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] != ' ') {
            tmp += s[i];
        } else {
            int k = stoi(tmp);
            if (min > k) {
                min = k;
            }
            if (max < k) {
                max = k;
            }
            tmp.clear();
        }
    }
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    return answer;
}