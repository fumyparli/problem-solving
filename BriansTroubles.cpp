#include <bits/stdc++.h>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string s) {
    int check[100] = {0};
    int i = 0;
    string answer = "";
    int flag = 0;
    while (true) {
        if (i >= s.size()) break;
        if (isupper(s[i])) {
            // cout << "upper i: " << i << '\n';
            int j = i + 1;
            char prev = s[j];
            while (true) {
                if (check[s[j] - 'a'] == 1 || j == s.size() + 1) {
                    flag = 1;
                    break;
                }
                if ((j == s.size() || prev != s[j]) && isupper(s[j - 1])) {
                    check[s[i + 1] - 'a'] = 1;
                    for (int k = i; k < j; k += 2) {
                        answer += s[k];
                    }
                    answer += " ";
                    i = j - 1;
                    break;
                }
                prev = s[j];
                j += 2;
            }
        } else if (islower(s[i])) {
            // cout << "lower i: " << i << '\n';
            if (check[s[i] - 'a'] == 1) {
                flag = 1;
                break;
            }
            check[s[i] - 'a'] = 1;
            char prev = s[i];
            int j = i + 1;
            while (true) {
                if (j >= s.size() || islower(s[j])) {
                    flag = 1;
                    break;
                }
                if (s[j] == prev) {
                    answer += s.substr(i + 1, j - i - 1);
                    answer += " ";
                    i = j;
                    break;
                }
                j++;
            }
        }
        if (flag == 1) {
            break;
        }
        i++;
    }
    if (flag == 1) {
        cout << "invalid";
        return "invalid";
    }
    answer.erase(answer.size() - 1);
    cout << answer;
    return answer;
}

int main() {
    solution("xBaCbDbEbAaBx");
}