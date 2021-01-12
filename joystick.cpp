#include <string>
#include <vector>
using namespace std;
string name;
int check[21];
int cal(int x) {
    int leftCnt = 0, rightCnt = 0;
    for (int i = x + 1; i < name.size(); i++) {
        if (i == name.size() - 1) {
            break;
        }
        if (check[i] == 0 && name[i] != 'A') {
            break;
        } else {
            rightCnt++;
        }
    }
    int i = x;
    while (true) {
        if (i - 1 < 0) i = name.size();
        if (check[--i] == 0 && name[i] != 'A') {
            break;
        } else {
            if (leftCnt > name.size()) {
                return -1;
            }
            leftCnt++;
        }
    }
    if (leftCnt < rightCnt) {
        return 0;
    } else {
        return 1;
    }
}

int solution(string s) {
    name = s;
    s = "";
    for (int i = 0; i < name.size(); i++) {
        s += 'A';
    }
    int answer = -1, i = 0, cnt = 0;
    int flag = 0;
    while (true) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1) + 1;
        s[i] = name[i];
        if (s == name) break;
        check[i] = 1;
        cnt++;
        if (cal(i) && flag == 0) {
            i++;
        } else {
            if (i - 1 < 0) i = name.size();
            i--;
            flag = 1;
        }
    }
    return answer;
}