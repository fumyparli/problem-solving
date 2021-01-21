#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i != 0 && s[i - 1] == ' ' && 'a' <= s[i] && s[i] <= 'z')
            s[i] -= 32;
        else if (s[i - 1] != ' ' && 'A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
    }
    if ('a' <= s[0] && s[0] <= 'z') s[0] -= 32;
    return s;
}