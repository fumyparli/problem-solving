#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    if (s.size() == 1)
        return 1;
    int answer = 987654321, cnt = 1;
    for (int i = 1; i <= s.size() / 2; i++) {
        string finalArr;
        string prev;
        for (int j = 0; j <= s.size(); j += i) {
            string a = s.substr(j, i);
            if (a == prev) {
                cnt++;
            } else {
                finalArr += (cnt - 1 ? to_string(cnt) : "");
                finalArr += prev;
                cnt = 1;
            }
            if (a.size() != i) {
                finalArr += a;
            }
            prev = a;
        }
        if (finalArr.size() < answer) {
            answer = finalArr.size();
        }
    }
    return answer;
}