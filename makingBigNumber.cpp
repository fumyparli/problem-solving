#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < number.size(); i++) {
        if (answer.size() == number.size() - k) break;
        char max = -1;
        int idx = -1;
        for (int j = i; j <= k + answer.size(); j++) {
            if (max < number[j]) {
                max = number[j];
                idx = j;
            };
        }
        i = idx;
        answer += max;
    }
    return answer;
}