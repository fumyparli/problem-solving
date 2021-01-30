#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (auto& i : new_id) {
        if ('A' <= i && i <= 'Z') {
            i += 32;
        }
    }
    auto iter = new_id.begin();
    while (true) {
        if (iter == new_id.end()) break;
        if (!(isdigit(*iter) || 'a' <= *iter && *iter <= 'z' || *iter == '-' || *iter == '_' || *iter == '.')) {
            new_id.erase(iter);
        } else {
            iter++;
        }
    }
    iter = new_id.begin();
    while (true) {
        if (iter == new_id.end()) break;
        if (*iter == '.' && *(iter + 1) == '.') {
            new_id.erase(iter + 1);
        } else {
            iter++;
        }
    }
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (*(new_id.end() - 1) == '.') new_id.erase(new_id.end() - 1);
    if (new_id.size() == 0) new_id += 'a';
    if (new_id.size() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }
    if (*(new_id.end() - 1) == '.') new_id.erase(new_id.end() - 1);
    if (new_id.size() <= 2) {
        while (true) {
            if (new_id.size() == 3) break;
            new_id += *(new_id.end() - 1);
        }
    }
    return new_id;
}