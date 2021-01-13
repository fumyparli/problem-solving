#include <string>
#include <vector>
using namespace std;

int isRightP(string u) {
    string s;
    for (int i = 0; i < u.size(); i++) {
        if (s.back() == '(' && u[i] == ')')
            s.pop_back();
        else
            s.push_back(u[i]);
    }
    if (s.empty()) return 1;
    return 0;
}

string reverse(string u) {
    u.erase(0, 1);
    u.pop_back();
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(')
            u[i] = ')';
        else
            u[i] = '(';
    }
    return u;
}

pair<string, string> getP(string p) {
    string u = "";
    string v = "";
    int cnt = 0, i = 0;
    for (; i < p.size(); i++) {
        if (i != 0 && cnt == 0) break;
        u += p[i];
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
    }
    for (; i < p.size(); i++) v += p[i];
    return {u, v};
}

string foo(string p) {
    if (p.size() == 0) return "";
    pair<string, string> uv = getP(p);
    if (isRightP(uv.first))
        return uv.first + foo(uv.second);
    else {
        string s = "(";
        s += foo(uv.second);
        s += ")";
        s += reverse(uv.first);
        return s;
    }
}

string solution(string p) {
    return foo(p);
}