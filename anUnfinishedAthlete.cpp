#include <bits/stdc++.h>
using namespace std;
multiset<string> s;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < participant.size(); i++) {
        s.insert(participant[i]);
    }
    for (int i = 0; i < completion.size(); i++) {
        auto it = s.find(completion[i]);
        s.erase(it);
    }
    auto it = s.begin();
    answer = *it;
    return answer;
}