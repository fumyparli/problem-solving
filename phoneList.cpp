#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            int end = min(phone_book[i].size(), phone_book[j].size());
            int flag = 0;
            for (int k = 0; k < end; k++) {
                if (phone_book[i][k] != phone_book[j][k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
            answer = false;
            return answer;
        }
    }
    return answer;
}