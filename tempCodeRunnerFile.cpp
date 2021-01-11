#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int sLen = number.size() - k;
    for (int i = 0; i < number.size(); i++) {
        int max = -1;
        int idx = i;
        for (int j = i; j <= i + sLen; j++) {
            if (max < number[j] - '0') {
                max = number[j] - '0';
                idx = j + 1;
            };
        }
        i = idx;
        answer += (max + '0');
    }
    return answer;
}

int main() {
    cout << solution("1231234", 3);
}