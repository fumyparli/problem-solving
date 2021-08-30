#include <bits/stdc++.h>
using namespace std;
char charSet[] = {'A', 'E', 'I', 'O', 'U'};

string bt;
int cnt;
int foo(string &word) {
    if (bt.size() > 5) return 0;
    if (bt == word) return cnt;
    cnt++;
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        bt.push_back(charSet[i]);
        ret = max(ret, foo(word));
        bt.pop_back();
    }
    return ret;
}

int solution(string word) {
    return foo(word);
}