#include <cstring>
#include <string>
#include <vector>
using namespace std;

string s;
vector<char> v;
int check[8];
int answer;
vector<string> d;

int getSub(char a, char b) {
    int aIdx, bIdx;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == a) {
            aIdx = i;
        }
        if (v[i] == b) {
            bIdx = i;
        }
    }
    return abs(aIdx - bIdx) - 1;
}

void foo() {
    if (v.size() == s.size()) {
        int flag = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i][3] == '<') {
                if (getSub(d[i][0], d[i][2]) >= d[i][4] - '0') {
                    flag = 1;
                    break;
                }
            }
            if (d[i][3] == '=') {
                if (getSub(d[i][0], d[i][2]) != d[i][4] - '0') {
                    flag = 1;
                    break;
                }
            }
            if (d[i][3] == '>') {
                if (getSub(d[i][0], d[i][2]) <= d[i][4] - '0') {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            answer++;
            return;
        }
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            v.push_back(s[i]);
            foo();
            v.pop_back();
            check[i] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    d = data;
    s = "ACFJMNRT";
    memset(check, 0, sizeof(check));
    answer = 0;
    foo();
    return answer;
}